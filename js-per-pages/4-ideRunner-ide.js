/*
pyodide-mkdocs-theme
Copyleft GNU GPLv3 🄯 2024 Frédéric Zinelli

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.
If not, see <https://www.gnu.org/licenses/>.
*/



import { jsLogger } from 'jsLogger'
import {
  choice,
  decompressLZW,
  downloader,
  freshStore,
  getTheme,
  PythonError,
  sleep,
  subscribeWhenReady,
  txtFormat,
  uploader,
} from 'functools'
import { clearPyodideScope } from '0-generic-python-snippets-pyodide'
import {
  IdeSplitScreenManager,
  IdeFullScreenGlobalManager,
  somethingFullScreen,
} from '4-ideLogistic-ide'















/**Hold logistic related to managing the Ace editor data (no behaviors implemented here:
 * see IdeRunner about that).
 * */
class IdeAceManager extends IdeSplitScreenManager {


  /**Add the `tests` section to the given code, joining them with the appropriated
   * string/comment if needed.
   * */
  _joinCodeAndPublicSections(userCode){
    const editorCode = [ userCode, this.publicTests ].filter(Boolean).join(CONFIG.lang.tests.msg)
    return editorCode
  }


  /**Save the current IDE content of the user, or the given code, into the localStorage
  * of the navigator.
  * */
  save(givenCode=""){   LOGGER_CONFIG.ACTIVATE && jsLogger("[Save]")
    const currentCode = givenCode || this.getCodeToTest()
    this.setStorage({code: currentCode, hash:this.srcHash})
  }


  applyCodeToEditorAndSave(exerciseCode, doSave=true){
    exerciseCode ||= ""
    this.editor.getSession().setValue(exerciseCode)
    if(doSave) this.save(exerciseCode)
  }


  /**Build (or extract if allowed) the initial code to put in the editor.
   * */
  getStartCode(attemptLocalStorageExtraction=false){
    let exerciseCode = ""

    if(attemptLocalStorageExtraction){
      exerciseCode = this.storage.code
    }
    if(!exerciseCode){
      exerciseCode = this._joinCodeAndPublicSections(this.userContent)
    }

    // Enforce at least one empty line of code in the editor, so that the terminal prompt
    // is always visible for IDEv:
    exerciseCode = exerciseCode.replace(/\n+$/,'')
    if(!exerciseCode) exerciseCode = '\n'

    return exerciseCode+"\n"
  }


  setStartingCode(options={}){

    const {extractFromLocalStorage, saveOnceApplied} = {
      extractFromLocalStorage:false,
      saveOnceApplied:true,
      ...options
    }
    const code = this.getStartCode(extractFromLocalStorage)
    this.applyCodeToEditorAndSave(code, saveOnceApplied)
    return code
  }
}















/**Handle `validations`: an array of arrays, holding info about N last validations.
 * As of now, the structure of the inner arrays is:
 *
 *      [done, formattedTimestamp, code]
 *
 * Validations have a "session" lifetime and are not store din the localStorage.
 * */
class IdeHistoryManager extends IdeAceManager {

  constructor(editorId){
    super(editorId)
    this.validations = []
  }

  pushValidation(code, done){
    const time = (Date()+'').split(' GMT')[0].slice(-8)
    this.validations.push([done, time, code])
    if(this.validations.length > CONFIG.N_IDE_VALIDATIONS){
      this.validations.splice(0, this.validations.length-CONFIG.N_IDE_VALIDATIONS)
    }
  }


  /**Update the color of an element to show a validation state (green/ref/normal).
   * By default, color the "check" button of the current IDE instance. To color another
   * element, pass in a second argument (jQuery collection).
   * @returns: the jQuery updated element/collection.
   * */
  updateValidationBtnColor(done=undefined, jElt=undefined){
    done ??= this.storage.done
    jElt ??= this.global.find("button[btn_kind=check]")
    const color = !done ? "unset" : done<0 ? 'red' : 'green'
    jElt.css('--ide-btn-color',  color)
    return jElt
  }


  clearValidations(){ this.validations.length = 0 }


  openHistoryModal(){

    // Exit if nothing to show or already displayed:
    const histId = `history_${ this.id }`
    if(!this.validations.length || $('#'+histId)[0]) return;

    const jHist = $(`<button id="${ histId }" class="history-box"></button>`)
    // Use button instead of div, so that focusout and co are actually working...

    const buttons = this.validations.map(data=>this._buildHistoryBtn(data,this))
    jHist.append(buttons)

    // Remove the window if left or clicking somewhere else:
    jHist.on('focusout mouseleave', function(e){ jHist.off().remove() })

    // Once entered, clicking on a button would close the window if the focusout event is still defined.
    jHist.on('mouseenter', function(e){ jHist.off('focusout') })

    // Make sure events are not transferred to upper level, (whatever they are)
    jHist.on('keyup click', function(e){ e.stopPropagation() ; e.preventDefault() })

    // Forbid going full screen and close if not needed anymore.
    jHist.on('keydown', function(e){
      e.stopPropagation() ; e.preventDefault()
      if(e.key=='Escape') jHist.off().remove()
    })

    // Force focus once mounter: activates focusout, in case the user never enters the panel.
    jHist.appendTo(this.global.find('button[btn_kind=check]')).focus()
  }


  _buildHistoryBtn([done, time, code], ideThis){

    const btn = $(`<button class="history-btn">${ time }</button>`)
    this.updateValidationBtnColor(done, btn)

    return btn.on('click', function(e){
      e.stopPropagation() ; e.preventDefault()
      ideThis.applyCodeToEditorAndSave(code)
      ideThis.updateValidationBtnColor(done)
    })
  }
}













/**Handle all elements of logics related to giving some kind of feedback to the user
 * (through terminal, UI colors, ...),
 */
class IdeFeedbackManager extends IdeHistoryManager {


  /**Relay method, to transfer stdout content from pyodide to the jQuery.terminal.
   * If @isPrint is true, the call has been done through the `bi_print` python function.
   * If @isPrint is false, then the call has been done through the `terminal_message` function.
   *
   * When the stdout is deactivated and @isPrint is false, the @key argument is required to
   * match the one given through the IDE macro `STD_KEY` argument.
   * */
  termFeedbackFromPyodide(key, msg, format, isPrint=false, newline=undefined){
    const hidden    =  isPrint && !this.allowPrint
    const forbidden = !isPrint && !this.allowPrint && key != this.stdKey
    if(forbidden){
      throw new PythonError("Cannot print to the terminal.")
    }
    if(!(isPrint && hidden)){
      super.termFeedbackFromPyodide(null, msg, format, isPrint, newline ?? !isPrint)
    }
  }


  /**Unconditionally update the counter of attempts with the given value.
   *
   * Handles Infinity as a security, in case the method is called with it anyway.
   * */
  setAttemptsCounter(nAttempts){
    this.data.attempts_left = nAttempts
    $(this.counterH).text(nAttempts===Infinity ? CONFIG.INFINITY : nAttempts)
  }


  //----------------------------------------------------------------------------------


  /**If the current action has been successful until now, display the appropriate
   * message in the terminal.
   * */
  codeSnippetEndFeedback(runtime, step, code){
    if(runtime.stopped || !step) return

    const playing = this.isPlaying()
    const intro   = playing ? "" : CONFIG.lang.validation.msg
    const section = CONFIG.lang[step].msg
    const ok      = CONFIG.lang.successMsg.msg

    let msg = `${ intro }${ section }: ${ ok }`   // Default section message
    if(!code) msg = ""                            // No default message if no code in the section...
    if(playing && !this.hasCheckBtn){             // ...but ensure the default ending message is shown,
      msg = CONFIG.lang.successMsgNoTests.msg     //    if this is "playing" dans nothing else to do after.
    }

    if(msg) this.terminalEcho(msg)

    // If no error yet and a validation button is present while running the editor's code only,
    // prepare a "very final" message reminding to try the validations:
    if(playing && this.hasCheckBtn){
      runtime.finalMsg = CONFIG.lang.unforgettable.msg
    }
  }



  /**Reveal solution and REMs on success, or if the counter reached 0 and the corr&REMs content
   * is still hidden, then prepare an appropriate revelation message if needed (`finalMsg`).
   *
   * Do not forget that any error related feedback has already been printed to the console, so
   * when it comes to feedback given in this method, it's only about a potential "final message".
   * */
  handleRunOutcome(runtime, allowCountDecrease, code){
    const success      = !runtime.stopped
    const done         = success ? 1:-1
    const isDelayed    = this.profile === CONFIG.PROFILES.delayedReveal
    const someToReveal = this.corrRemsMask && this.hiddenDivContent && (!this.profile || isDelayed)

    LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - handleRunOutcome")
    // console.log("[OutCome]", JSON.stringify({
    //   success, pof:this.profile, revealable, hidden:this.hiddenDivContent,
    //   allowCountDecrease: !!allowCountDecrease, mask:this.corrRemsMask, N:this.attemptsLeft
    // }))

    this.pushValidation(code, done)
    this.setStorage({done})
    this.updateValidationBtnColor(done)

    if(allowCountDecrease && (!success || isDelayed)){
      this.decreaseIdeCounter()
    }

    // Reveal if success and not delayed, or if attempts==0 (means last error, are last delayed)
    const isRevelation =  someToReveal && (success && !isDelayed || this.attemptsLeft===0)

    /*If success, a custom final message has to be built:
          - If the revelation already occurred, return no message at all
          - If some profile forbids the revelation, or if nothing to reveal, just congratulate the user.
          - Make sure a success on "delayed" profile doesn't trigger a final message.

      WARNING: someToReveal is different from "already revealed".
     */
    const isSuccessNoReveal = success && this.hiddenDivContent && !isDelayed

    if(isRevelation){
      LOGGER_CONFIG.ACTIVATE && jsLogger("[OutCome]", 'reveal!', success)
      runtime.finalMsg = success ? this._buildSuccessMessage(someToReveal, isDelayed)
                                 : this._getSolRemTxt(false)
      this.revealSolutionAndRems()

    }else if(isSuccessNoReveal){
      // Always display the "bravo" message on success, if corr&REMs exist but are not revealable
      runtime.finalMsg = this._buildSuccessMessage(someToReveal, isDelayed)
    }
  }


  /**Decrease the number of attempts left, EXCEPT when:
   *    - the solution is already revealed,
   *    - the number of attempts is infinite,
   *    - there are no attempts left (redundant with revelation condition, but hey...).
   */
  decreaseIdeCounter(){
    LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - decreaseIdeCounter")
    if(!this.hiddenDivContent) return    // already revealed => nothing to change.

    // Allow going below 0 so that triggers once only for failure.
    const nAttempts = Math.max(-1, this.attemptsLeft - 1)

    // Update the GUI counter if needed:
    if(Number.isFinite(nAttempts) && nAttempts >= 0){
      this.setAttemptsCounter(nAttempts)
    }
  }


  /**Reveal corr and/or REMs (VIS or not) contents.
   * When reaching this method, it is already sure by contract that the revelation must occur.
   * The only piece of contract this method is holding is that it flags the revelation as done,
   * and decides if the div content has to be decompressed or not on the way.
   *
   * @waitForMathJax: if true, the call is done with profile=="revealed", so mathjax might not be
   * ready yet, and the update must be delayed.
   * */
  revealSolutionAndRems(waitForMathJax=false){
    LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - Enter revealSolutionAndRems")

    // Need to check here _one more_ time against hiddenDivContent because of the "show"
    // button logic...
    if(this.hiddenDivContent){
      LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - revealed!")

      const sol_div = $(this.solutionH)

      if(this.isEncrypted){
        const compressed = sol_div.text().trim()
        const content    = compressed && decompressLZW(compressed, "ides.encrypt_corrections_and_rems")
        sol_div.html(content)
        this.data.is_encrypted = false  // Never decompress again
      }
      sol_div.attr('class', '')         // Unhide
      this.hiddenDivContent = false     // Never reveal again (last in case of errors...)

      // Enforce formatting
      if(waitForMathJax){
        subscribeWhenReady(
          "revealOnLoad", mathJaxUpdate, {runOnly:true, waitFor:()=>CONFIG.subscriptionReady.mathJax}
        )
      }else{
        mathJaxUpdate()
      }

      /* DOESN'T WORK
      // Enforce mermaid rendering if any
      try{
        // Need to make an async call, but i don't want to make this method an async one...
        setTimeout(async ()=>console.log('yup?') || await mermaid.run())
      }catch(e){}
      //*/
    }
  }


  /**If @isDelayed is true, there are no tests/secrets, so:
   *    - Do not congratulate the user
   *    - if something revealable, announce the revelation, otherwise say nothing special
   *
   * If @isDelayed is false, build:
   *    - the complete success message if something to reveal
   *    - only the bravo message otherwise.
   */
  _buildSuccessMessage(revealable, isDelayed){
    const moreInfo = revealable ? this._getSolRemTxt(true) : ""
    if(isDelayed){
      return moreInfo && txtFormat.stress(moreInfo)
    }
    const emo = choice(CONFIG.MSG.successEmojis)
    return `${ CONFIG.lang.successHead.msg } ${ emo } ${ CONFIG.lang.successHeadExtra.msg }${ moreInfo }`
  }


  /**Routine building the final success or failure message, assembling the various parts
   * of CONFIG.lang as needed.
   * */
  _getSolRemTxt(isSuccess){
    if(!this.corrRemsMask) return ""

    const hasCorr  = this.corrRemsMask & 1
    const hasRems  = this.corrRemsMask & 2
    const hasBoth  = this.corrRemsMask == 3
    const msg      = []
    const sentence = []

    const pushSentence = (prop,kind='msg') => sentence.push(CONFIG.lang[prop][kind])

    msg.push( isSuccess
      ? "\n"+CONFIG.lang.successTail.msg
      : CONFIG.lang.failHead.msg
    )

    if(hasCorr) pushSentence('revealCorr')
    if(hasBoth) pushSentence('revealJoin')
    if(hasRems) pushSentence('revealRem')

    if(!isSuccess){
      // Ensure capitalization of the beginning of the error feedback
      if(sentence.length){
        sentence[0] = _.capitalize(sentence[0])
      }
      const kind = hasBoth || hasRems ? 'plural':'msg'
      pushSentence('failTail', kind)
    }

    msg.push(...sentence)
    const output = msg.join(' ').trimEnd() + "."

    // console.log("[OutComeSolRemTxt]", JSON.stringify({isSuccess, msg, mask:this.corrRemsMask, sentence, output}))
    return output
  }
}














/**Holds the running/code management logistic for IdeRunner.
 * */
class IdeRunnerLogic extends IdeFeedbackManager {


  /**Is the current action "running the public tests"?
   * */
  isPlaying(){  return this.running.includes(CONFIG.runningMode.play) }

  /**Is the current action "running the validation tests"?
   * */
  isChecking(){ return this.running.includes(CONFIG.runningMode.validate) }


  /**Does nothing, but catch any call on the parent class, which would raise an error
   * because prefillTerm is undefined, for IDEs.
   * */
  prefillTermIfAny(){}


  // @OVERRIDE
  async applyAutoRun(){
    await this._defaultAutoRun()
  }




  /**Things to display in the terminal at the very beginning of the executions.
   * */
  terminalDisplayOnIdeStart(){
    this.terminalEcho(CONFIG.lang.runScript.msg)
  }



  async setupRuntimeIDE() {
    LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - setupRuntimeIDE IdeRunner")

    this.terminalAutoWidthOnResize()

    // Save before anything else, in case an error occurs somewhere...
    const editorCode = this.getCodeToTest()
    this.save(editorCode)
    this.storeUserCodeInPython('__USER_CODE__', editorCode)

    this.terminal.pause()             // Deactivate user actions in the terminal until resumed
    this.terminal.clear()             // To do AFTER pausing... (otherwise, prompt is showing up)
    this.terminalDisplayOnIdeStart()  // Handle the terminal display for the current action
    await sleep(this.delay)           // Terminal "blink", so that the user always sees a change

    return await this.setupRuntimeTrackingEnvRun()
  }



  async teardownRuntimeIDE(runtime) {
    LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - IdeRunner teardownRuntime")

    // Restore default state first, in case a validation occurred (=> restore stdout behaviors!)
    runtime.refreshStateWith()

    // Handle any extra final message (related to revelation of solutions & REMs)
    if(runtime.finalMsg) this.giveFeedback(runtime.finalMsg, null)

    await this.teardownRuntime(runtime)

    this.storeUserCodeInPython('__USER_CODE__', "")
  }



  /**Build the public tests runner routine.
   * */
  playFactory(runningMan=CONFIG.runningMode.play){
    return this.lockedRunnerWithBigFailWarningFactory(
      runningMan,
      this.setupRuntimeIDE,
      this.playThroughRunner,
      this.teardownRuntimeIDE,
    )
  }



  async playThroughRunner(runtime){
    const code = this.getCodeToTest()
    await this.runPythonCodeWithOptionsIfNoStdErr(code, runtime, CONFIG.section.editor)
  }



  /**Build the validation tests runner routine.
   * */
  validateFactory(runningMan=CONFIG.runningMode.validate){
    return this.lockedRunnerWithBigFailWarningFactory(
      runningMan,
      this.setupRuntimeIDE,
      this.validateThroughRunner,
      this.teardownRuntimeIDE,
    )
  }



  async validateThroughRunner(runtime){

    // env section is behaving like the editor one (should be changed...?)
    let decrease_count = this.canDecreaseAttempts(CONFIG.section.editor)
    const code = this.getCodeToTest()

    // If an error already occurred, stop everything...
    if(runtime.stopped){

      // ... but decrease the number attempts and run teardown if this was AssertionError.
      if(runtime.isAssertErr){
        this.handleRunOutcome(runtime, decrease_count, code)
      }

    }else{

      const validation_state = {
        autoLogAssert:    this.autoLogAssert,
        purgeStackTrace:  this.showOnlyAssertionErrorsForSecrets,
        withStdOut:      !this.deactivateStdoutForSecrets,
      }
      const toRun = [
        [code,             CONFIG.section.editor,  {}],
        [this.publicTests, CONFIG.section.public,  validation_state],
        [this.secretTests, CONFIG.section.secrets, validation_state],
      ]

      for(const [code, testSection, state] of toRun){
        LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - Run validation step:", testSection)

        runtime.refreshStateWith(state)
        await this.runPythonCodeWithOptionsIfNoStdErr(code, runtime, testSection)

        if(runtime.stopped){
          decrease_count = this.canDecreaseAttempts(testSection)
          break
        }
      }

      // Reveal solution and REMs on success, or if the counter reached 0 and the corr&REMs content
      // is still hidden, then prepare an appropriate revelation message if needed (`finalMsg`).
      this.handleRunOutcome(runtime, decrease_count, code)
    }
  }


  /**Return true if the current section allow to decrease the number of attempts,
   * during a validation.
   * */
  canDecreaseAttempts(testSection){
    const wanted      = CONFIG.section[ this.decreaseAttemptsOnUserCodeFailure ]
    const allowedFrom = CONFIG.sectionOrder[ wanted ]
    const currentAt   = CONFIG.sectionOrder[ testSection ]
    const canDecrease = currentAt >= allowedFrom
    return canDecrease
  }



  //--------------------------------------------------------------------



  /**Build the correction validation runner routine.
   * NOTE: the pyodideLock setup is not correct here (swaps done outside of it), but it shouldn't
   *       ever cause troubles, as long as this method is not used in the IdeTester objects.
   * */
  validateCorrFactory(){
    return async (e)=>{
      LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - corr_btn start")

      const codeGetter   = this.getCodeToTest
      const currentCode  = this.getCodeToTest()
      const profile      = this.profile
      this.getCodeToTest = ()=>this.corrContent
      this.data.profile  = null    // REMINDER: getters without setters, so need inner update!

      let out
      try{
        out = await this.runner(e)
      }finally{
        LOGGER_CONFIG.ACTIVATE && jsLogger("[CheckPoint] - corr_btn validation done")
        this.data.profile  = profile
        this.getCodeToTest = codeGetter
        this.save(currentCode)     // Ensure the corr content doesn't stay stored in localStorage
      }
      return out
    }
  }
}














/**Controller. Linking behaviors and UI.
 * */
export class IdeRunner extends IdeRunnerLogic {


  /**Process to "re-initiate" the internal state of the IDE (useful for testing) */
  _init(){
    super._init()
    this.srcAttemptsLeft = this.attemptsLeft
  }


  // @Override
  build(){

    // Create and define this.editor + define all needed listeners:
    this.setupAceEditor()
    this.bindIdeButtons()

    // Try to restore a previous session, or extract default starting code, but skip localStorage
    // update (this way, the user is not bothered with updates of the starting content of an IDE
    // they didn't even tried yet, when the author is making updates):
    this.setStartingCode({extractFromLocalStorage: true, saveOnceApplied: false})
    this.editor.resize();

    super.build()

    this.announceCodeChangeBasedOnSrcHash()

    // Add the terminal resize listener (because of the intermediate div wrappers, IDE's terminal
    // will not resize automatically):
    window.addEventListener( 'resize', _.throttle(
      this.windowResizeHandler.bind(this), 50, {leading:false, trailing:true}
    ))

    // Check for initial actions on page load:
    if(this.profile===CONFIG.PROFILES.revealed){
      this.revealSolutionAndRems(true)
    }
    if(this.twoCols){
      this.switchSplitScreenFromButton(null, false)
    }
  }



  /**Create and setup the ACE editor for the current Ide instance.
   * */
  setupAceEditor() {

    // https://github.com/ajaxorg/ace/wiki/Configuring-Ace
    const options = {
        autoScrollEditorIntoView: false,
        copyWithEmptySelection:   true,               // active alt+flèches pour déplacer une ligne, aussi
        enableBasicAutocompletion:true,
        enableLiveAutocompletion: false,
        enableSnippets:           true,
        tabSize:                  4,
        useSoftTabs:              true,               // Spaces instead of tabs
        navigateWithinSoftTabs:   false,              // this is _fucking_ actually "Atomic Soft Tabs"...
        printMargin:              false,              // hide ugly margins...
        maxLines:                 this.maxIdeLines,
        minLines:                 this.minIdeLines,
        mode:                     "ace/mode/python",
        theme:                    getTheme(),
        fontSize:                 CONFIG.editorFontSize,
        fontFamily:               [CONFIG.editorFontFamily, "Monaco", "Menlo", "Ubuntu Mono", "Consolas",
                                   "Source Code pro", "source-code-pro", "monospace"],   // Fix apple troubles...
    }

    this.editor = ace.edit(this.id, options);
    this.runner = this.playFactory()
    this.gutter = this.global.find('div.ace_gutter-layer')

    if(CONFIG._devMode) CONFIG.editors[this.id] = this.editor

    // Kbd shortcuts:
    this.editor.commands.bindKey(
        { win: "Ctrl-Space", mac: "Cmd-Space" }, "startAutocomplete"
    )
    this.editor.commands.addCommand({
        name: "commentTests",
        bindKey: { win: "Ctrl-I", mac: "Cmd-I" },
        exec: this.toggleComments.bind(this),
    })
    this.editor.commands.addCommand({
        name: "runPublicTests",
        bindKey: { win: "Ctrl-S", mac: "Cmd-S" },
        exec: this.runner,
    })
    if(this.hasCheckBtn){
      this.editor.commands.addCommand({
        name: "runValidationTests",
        bindKey: { win: "Ctrl-Enter", mac: "Cmd-Enter" },
        exec: this.validateFactory(),
      })
    }

    // Content of the editor is saved every `CONFIG.ideKeyStrokesSave` keystrokes:
    let nChange = 0;
    this.editor.addEventListener("input", _=>{
        if(nChange++ >= CONFIG.ideKeyStrokesSave){
          nChange=0
          this.save()
        }
    })
  }



  bindIdeButtons(){

    // (Doesn't work to catch the Esc applying "exit full screen"... :/ )
    this.global.on('keydown', this.respondToKeyDown.bind(this))

    // Add fullscreen activation binding, but NOT through the ACE editor commands
    // cannot control the exit :/ )
    this.global.on('keyup', this.respondToEscapeKeyUp.bind(this))

    // Bind editor extra buttons:
    this.global.find(".comment.tooltip" ).on("click", this.toggleComments.bind(this))
    this.global.find(".ide-full-screen" ).on("click", this.switchFullScreenFromButton.bind(this))
    this.global.find(".ide-split-screen").on("click", this.switchSplitScreenFromButton.bind(this))
                                         .addClass('deactivated')


    // Bind all buttons below the IDE
    const ideThis = this
    this.global.find("button").each(function(){
      const btn  = $(this)
      const kind = btn.attr('btn_kind')
      let callback

      switch(kind){
        case 'play':      callback = ideThis.playFactory() ; break
        case 'check':     callback = ideThis.runner = ideThis.validateFactory()
                          ideThis.updateValidationBtnColor()
                          break

        case 'download':  callback = _=>ideThis.download() ; break
        case 'upload':    callback = _=>uploader( txt=>{
                                        ideThis.applyCodeToEditorAndSave(txt)
                                        ideThis.focusEditor()
                                      }) ; break

        case 'restart':   callback = _=>ideThis.restart() ; break
        case 'save':      callback = _=>{ideThis.save(); ideThis.focusEditor()} ; break
        case 'zip':       callback = ideThis.buildZipExportsToolsAndCbk(btn) ; break

        case 'corr_btn':  if(!CONFIG.inServe) return;
                          callback = ideThis.validateCorrFactory() ; break
        case 'show':      if(!CONFIG.inServe) return;
                          callback = ()=>ideThis.revealSolutionAndRems() ; break

        default:          throw new Error(`Y'should never get there, mate... (${ kind })`)
      }
      btn.on('click', callback)

      if(kind=='check') btn.on('contextmenu', function(e){
        e.stopPropagation()
        e.preventDefault()
        ideThis.openHistoryModal()
      })
    })
  }


  // @Override
  getTerminalBindings(){

    // Ensure the focus is given back to the terminal after an action triggered from it!
    const asyncTerminalFocus=(cbk)=>async e=>{
      await cbk(e)
      this.editor.blur()
      this.terminal.focus()
    }
    const bindings = {
      ...super.getTerminalBindings(),
      'CTRL+I': asyncTerminalFocus(this.toggleComments.bind(this)),
      'CTRL+S': asyncTerminalFocus(this.playFactory()),
      ...(
        this.hasCheckBtn ? {'CTRL+ENTER': asyncTerminalFocus(this.validateFactory())} : {}
      ),
    }
    return bindings
  }


  windowResizeHandler(){
    // When going full screen the resize would trigger this logic, while the computations have
    // already been done correctly (with goingFullScreen argument), so skip:
    if(this.isInSplit && !somethingFullScreen()){
      const topDivH = this.setupTopDivHeight()
      this.ideScreenModeVerticalResize({topDivH})
    }
    this.terminalAutoWidthOnResize()
  }



  respondToKeyDown(event){
    // Doesn't work to catch the Esc applying "exit full screen"... :/
    IdeFullScreenGlobalManager.currentIde = this  // Register the IDE currently in use
  }


  async respondToEscapeKeyUp(event){
    if(
      event.key == 'Escape'
      && !IdeFullScreenGlobalManager.someMenuOpened
      && !this.guiIdeFlags.escapeIdeSearch
      && !somethingFullScreen()
    ){
      this.requestFullScreen()
      // The browser already handles on its own going out of fullscreen with escape => no else needed

    }else if(event.altKey && event.key==':'){
      this.switchSplitScreenFromButton(event)
    }
    this.guiIdeFlags.escapeIdeSearch = false
  }


  //--------------------------------------------------------------



  /**Extract the current content of the given editor, explore it, and toggle all the LOCs
   * found after the `TestToken` token.
   *
   * Rules for toggling or not are:
   *      - leading spaces do not affect the logic.
   *      - comment out if the first non space character is not "#".
   *      - if the first non space char is "#" and there is no spaces after it, uncomment.
   * */
  toggleComments(e) {
    if(e && e.preventDefault) e.preventDefault()

    const codeLines   = this.getCodeToTest().split('\n')
    const pattern     = CONFIG.lang.tests.as_pattern
    const iTestsToken = codeLines.findIndex(s=>pattern.test(s))

    /// No tests found:
    if(iTestsToken<0) return;

    const toggled = codeLines.slice(iTestsToken+1).map(s=>{
        return s.replace(CONFIG.COMMENTED_PATTERN, (_,spaces,head,tail)=>{
            if(head=='#' && tail!=' ') return spaces+tail
            if(head!='#') return spaces+'#'+head+tail
            return _
        })
    })
    codeLines.splice(iTestsToken+1, toggled.length, ...toggled)
    const repl = codeLines.join('\n')
    this.applyCodeToEditorAndSave(repl)
    this.focusEditor()
  }



  /**Download the current content of the editor to the download folder of the user.
   * */
  download(){   LOGGER_CONFIG.ACTIVATE && jsLogger("[Download]")

    let ideContent = this.getCodeToTest() + "" // enforce stringification in any case
    downloader(ideContent, this.pyName)
    this.focusEditor()
  }


  /**Reset the content of the editor to its initial content, and reset the localStorage for
   * this editor on the way.
   * */
  restart(){    LOGGER_CONFIG.ACTIVATE && jsLogger("[Restart]")

    const code   = this.setStartingCode({extractFromLocalStorage: false, saveOnceApplied: true})
    this.storage = freshStore(code, {}, this)
    this.updateValidationBtnColor()
    this.clearValidations()
    if(Number.isFinite(this.srcAttemptsLeft)){
      this.setAttemptsCounter(this.srcAttemptsLeft)
    }
    $("#solution_" + this.id).addClass('py_mk_hidden')
    this.hiddenDivContent = true
    this.terminal.clear()
    clearPyodideScope()
    this.focusEditor()
  }
}



CONFIG.CLASSES_POOL.Ide = IdeRunner