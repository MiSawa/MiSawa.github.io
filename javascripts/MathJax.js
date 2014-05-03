document.write("<script type='text/javascript' src='http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML&delayStartupUntil=configured'></script>")
document.write("<meta http-equiv='X-UA-Compatible' CONTENT='IE=EmulateIE7'/>")
document.write("<script type='text/javascript'>(" + function(){
MathJax.Hub.Config({
    extensions: ["tex2jax.js","TeX/AMSmath.js","TeX/AMSsymbols.js",
                 "TeX/noErrors.js","TeX/noUndefined.js"],
    tex2jax: {
        inlineMath: [ ['$','$'], ["\\(","\\)"] ],
        displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
    },
    TeX: {
        equationNumbers: { autoNumber: "AMS" },
        Macros: {
            N: '{\\mathbb{N}}',
            Z: '{\\mathbb{Z}}',
            Q: '{\\mathbb{Q}}',
            R: '{\\mathbb{R}}',
            C: '{\\mathbb{C}}',
            abs: ['{\\left| #1 \\right|}', 1],
        }
    },
});
MathJax.Hub.Configured();
}.toString() + ")()</script>");

