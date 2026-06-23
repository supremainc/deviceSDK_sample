(function () {
    var path = window.location.pathname;
    var isKorean = path.indexOf('/ko/') !== -1;

    var targetPath, label;
    if (isKorean) {
        targetPath = path.replace('/ko/', '/');
        label = 'English';
    } else {
        var lastSlash = path.lastIndexOf('/');
        targetPath = path.substring(0, lastSlash) + '/ko' + path.substring(lastSlash);
        label = '한국어';
    }

    function insertBtn() {
        var btn = document.createElement('a');
        btn.href = targetPath;
        btn.textContent = label;
        btn.style.cssText = [
            'display:inline-block',
            'padding:2px 10px',
            'margin-left:8px',
            'background:#0a73bf',
            'color:#fff',
            'border-radius:4px',
            'font-size:13px',
            'text-decoration:none',
            'vertical-align:middle',
            'white-space:nowrap',
        ].join(';');

        // doxygen-awesome: search box 옆에 삽입
        var searchBox = document.getElementById('MSearchBox');
        if (searchBox && searchBox.parentNode) {
            searchBox.parentNode.insertBefore(btn, searchBox);
            return;
        }

        // 일반 Doxygen: nav 우측에 삽입
        var navRow = document.getElementById('navrow1') ||
                     document.querySelector('.sm-dox');
        if (navRow) {
            navRow.appendChild(btn);
            return;
        }

        // 최후 수단: fixed 위치
        btn.style.cssText += ';position:fixed;top:10px;right:10px;z-index:9999';
        document.body.appendChild(btn);
    }

    if (document.readyState === 'loading') {
        document.addEventListener('DOMContentLoaded', insertBtn);
    } else {
        insertBtn();
    }
})();
