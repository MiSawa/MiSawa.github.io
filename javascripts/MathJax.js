document.write("<script async type='text/javascript' src='https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-AMS-MML_HTMLorMML&delayStartupUntil=configured'></script>");
document.write("<meta http-equiv='X-UA-Compatible' CONTENT='IE=EmulateIE7'/>");
(function(){
    const configureOrRetry = () => {
        if (typeof MathJax === 'undefined') {
            setTimeout(configureOrRetry, 10);
            return;
        }
        MathJax.Hub.Config({
            extensions: ["tex2jax.js","TeX/AMSmath.js","TeX/AMSsymbols.js",
                "TeX/noErrors.js","TeX/noUndefined.js"],
            tex2jax: {
                inlineMath: [ ['$','$'], ["\\(","\\)"] ],
                displayMath: [ ['$$','$$'], ["\\[","\\]"] ],
                processExcapes: true
            },
            TeX: {
                equationNumbers: { autoNumber: "AMS" },
                Macros: {
                    N: '{\\mathbb{N}}',
                    Z: '{\\mathbb{Z}}',
                    Q: '{\\mathbb{Q}}',
                    R: '{\\mathbb{R}}',
                    C: '{\\mathbb{C}}',
                    divides: '{\\mid}',
                    abs: ['{\\left| #1 \\right|}', 1],
                    relmiddle: ['\\mathrel{}\\middle#1\\mathrel{}', 1],
                    setmid: '\\relmiddle|',
                    set: ['\\left\\{\\,#1\\,\\right\\}', 1],
                }
            },
        });
        MathJax.Hub.Configured();
    };
    configureOrRetry();
})();

