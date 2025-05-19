// Must be defined to fulfill the legacy subscription logistic:
function mathJaxUpdate(){}

subscribeWhenReady('MathJax')


window.MathJax = {
  startup: {
    ready: () => {
      LOGGER_CONFIG.ACTIVATE && console.log("[MathJax] - Setting up");
      MathJax.startup.defaultReady();
      LOGGER_CONFIG.ACTIVATE && console.log("[MathJax] - Ready");
    },
  },
  loader: {
    load: ['[tex]/cancel', 'output/svg', '[tex]/color']
  },
  tex: {
    packages: {'[+]': ['cancel', 'color']},
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