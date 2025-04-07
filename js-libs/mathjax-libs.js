function mathJaxUpdate(){
    jsLogger('[MathJax] - Page formatting')
  
    window.MathJax.startup.output.clearCache()
    window.MathJax.typesetClear()
    window.MathJax.texReset()
    window.MathJax.typesetPromise()
  }
  const mathJaxIsReady = subscribeWhenReady('mathJax', mathJaxUpdate)
  
  
  window.MathJax = {
    startup: {
      ready: () => {
        jsLogger("[MathJax] - Setting up");
        MathJax.startup.defaultReady();
        jsLogger("[MathJax] - Ready");
        mathJaxIsReady()
        mathJaxUpdate()
      },
    },
    loader: {load: ['[tex]/cancel', 'output/svg', '[tex]/color']},
    tex: {
      packages: {'[+]': ['cancel','color']},
      inlineMath: [["\\(", "\\)"]],
      displayMath: [["\\[", "\\]"]],
      processEscapes: true,
      processEnvironments: true,
    },
    options: {
      ignoreHtmlClass: ".*|",
      processHtmlClass: "arithmatex",
    },
  }