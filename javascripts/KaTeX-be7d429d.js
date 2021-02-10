document.write('<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/katex@0.12.0/dist/katex.min.css" integrity="sha384-AfEj0r4/OFrOo5t7NnNe46zW/tFgW6x/bCJG8FqQCEo3+Aro6EYUG4+cU+KJWu/X" crossorigin="anonymous">');
document.write('<script defer src="https://cdn.jsdelivr.net/npm/katex@0.12.0/dist/katex.min.js" integrity="sha384-g7c+Jr9ZivxKLnZTDUhnkOnsh30B4H0rpLUpJ4jAIKs4fnJI+sEnkvrMWph2EDg4" crossorigin="anonymous"></script>')
document.write('<script defer src="https://cdn.jsdelivr.net/npm/katex@0.12.0/dist/contrib/auto-render.min.js" integrity="sha384-mll67QQFJfxn0IYznZYonOWZ644AWYC+Pt2cHqMaRhXVrursRwvLnLaebdGIlYNa" crossorigin="anonymous"></script>');

// document.write("<meta http-equiv='X-UA-Compatible' CONTENT='IE=EmulateIE7'/>");
(function(){
    const configureOrRetry = () => {
        if (typeof renderMathInElement === 'undefined') {
            setTimeout(configureOrRetry, 10);
            return;
        }
        renderMathInElement(document.body, {
            delimiters: [
                {left: "$$", right: "$$", display: true},
                {left: "$", right: "$", display: false},
                {left: "\\(", right: "\\)", display: false},
                {left: "\\[", right: "\\]", display: true},
            ],
            macros: {
                // '\\N': '{\\mathbb{N}}',
                // '\\Z': '{\\mathbb{Z}}',
                '\\Q': '{\\mathbb{Q}}',
                // '\\R': '{\\mathbb{R}}',
                '\\C': '{\\mathbb{C}}',
                '\\divides': '{\\mid}',
                '\\abs': '{\\left| #1 \\right|}',
                '\\relmiddle': '\\mathrel{}\\middle#1\\mathrel{}',
                '\\setmid': '\\relmiddle|',
                '\\set': '\\left\\{\\,#1\\,\\right\\}',
            },
        });
    };
    configureOrRetry();
})();

