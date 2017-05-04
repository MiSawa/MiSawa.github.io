document.write("<script type='text/javascript' src='https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.1/MathJax.js?config=TeX-AMS-MML_HTMLorMML&delayStartupUntil=configured'></script>")
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
            divides: '{\\mid}',
            abs: ['{\\left| #1 \\right|}', 1],
        }
    },
});
MathJax.Hub.Configured();
}.toString() + ")()</script>");
document.write("<div style=\"display:none\">");
document.write("\\(\\def\\relmiddle#1{\\mathrel{}\\middle#1\\mathrel{}}\\)");
document.write("\\(\\def\\setmid{\\mathrel{}\\middle|\\mathrel{}}\\)");
document.write("\\(\\def\\set#1{\\left\\{\\,#1\\,\\right\\}}\\)");
document.write("</div>");

