// When the page is loaded
document.addEventListener("DOMContentLoaded", () => {
    // Make all external links open on a new tab
    // - https://www.w3schools.com/css/css_attribute_selectors.asp
    let external_links = Array.from(document.querySelectorAll(".md-typeset a[href^=http]"));
    let repo_link = Array.from(document.querySelectorAll(".md-header__source a[href^=http]"));
    for (const link of external_links.concat(repo_link)) {
        link.target = "_blank"
    }

    // Put <code> around cpp reference links regardless of macros
    let cpp_reference_links = Array.from(document.querySelectorAll('.md-typeset a[href*="cppreference"]'));
    let open_std_links = Array.from(document.querySelectorAll('.md-typeset a[href*="open-std"]'));
    let futures_reference_link = Array.from(document.querySelectorAll('.md-typeset a[href*="/futures/reference/"]'));
    for (const link of cpp_reference_links.concat(open_std_links).concat(futures_reference_link)) {
        let already_inside_code_tag = link.parentElement.tagName !== undefined && link.parentElement.tagName.toUpperCase() === 'CODE'
        let already_has_code_tag = link.firstChild.tagName !== undefined && link.firstChild.tagName.toUpperCase() === 'CODE'
        let is_code_reference = link.innerHTML.startsWith('std::') || link.href.includes('/futures/reference/')
        if (already_inside_code_tag || already_has_code_tag || !is_code_reference) {
            continue;
        }
        link.innerHTML = "<code>" + link.innerHTML + "</code>"
    }

    // Fix bug in doxybook reference anchors
    let brokenAnchors = ['#function-', '#variable-', '#using-']
    for (const anchor of brokenAnchors) {
        for (const link of futures_reference_link) {
            anchorPos = link.href.lastIndexOf(anchor);
            if (anchorPos !== -1) {
                let splitPos = anchorPos + anchor.length;
                let linkLhs = link.href.substr(0, splitPos);
                let linkRhs = link.href.substr(splitPos);
                link.href = linkLhs + linkRhs.replaceAll('-', '_');
            }
        }
    }
})