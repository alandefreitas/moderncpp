#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Test single expression
    if (regex_match("subject", regex("(sub)(.*)"))) {
        cout << "subject matches expression (sub)(.*)" << endl;
    }

    // Test string
    const char cstr[] = "subject";
    string s("subject");
    regex e("(sub)(.*)");
    if (regex_match(s, e)) {
        cout << "subject matches expression (sub)(.*)" << endl;
    }

    // Test range
    if (regex_match(s.begin(), s.end(), e)) {
        cout << "subject matches expression (sub)(.*)" << endl;
    }

    // Get match results for char*
    // cmatch is the same as match_results<const char*> cm;
    cmatch cm;
    regex_match(cstr, cm, e);
    cout << "literal string with " << cm.size() << " matches" << endl;
    cout << "The literal string matches were: ";
    for (const auto &i : cm) {
        cout << "[" << i << "] ";
    }
    cout << endl;

    // Get match results for string
    // same as match_results<string::const_iterator> sm;
    smatch sm;
    regex_match(s, sm, e);
    cout << "string object with " << sm.size() << " matches" << endl;
    cout << "The string matches were: ";
    for (const auto &i : sm) {
        cout << "[" << i << "] ";
    }
    cout << endl;

    // Get match results for string range
    regex_match(s.cbegin(), s.cend(), sm, e);
    cout << sm.size() << " matches" << endl;

    // Using flags to determine behavior
    regex_match(cstr, cm, e, regex_constants::match_default);

    // Iterate substrings with matches
    std::string ss = "foo bar 123";
    std::regex r("([a-zA-Z]+)|(d+)");
    std::sregex_iterator first_str_match =
        std::sregex_iterator(ss.begin(), ss.end(), r);
    for (auto i = first_str_match; i != std::sregex_iterator(); ++i) {
        std::smatch m = *i;
        std::cout << "Match value: " << m.str() << " at Position "
                  << m.position() << '\n';
        for (size_t index = 1; index < m.size(); ++index) {
            if (!m[index].str().empty()) {
                std::cout << "Capture group ID: " << index - 1 << std::endl;
                break;
            }
        }
    }

    // Concatenate regexes: conjunction
    string var = "first second third forth";
    if (regex_match(var, sm, regex("(.*) (.*) (.*) (.*)"))) {
        for (size_t i = 1; i < sm.size(); i++) {
            cout << "Match " << i << ": " << sm[i] << " at position "
                 << sm.position(i) << endl;
        }
    }

    // Concatenate regexes: disjunction
    // This strategy does not work when there are internal capture groups
    var = "user/32";
    smatch sm2;
    auto implode = [](const std::vector<std::string> &strs,
                      const std::string &delim) {
        std::stringstream s;
        copy(strs.begin(), strs.end(),
             ostream_iterator<string>(s, delim.c_str()));
        return s.str();
    };
    std::vector<std::string> routes = {"welcome", "user/\\d+", "post/[a-zA-Z]+",
                                       "about"};
    regex disjunction("(" + implode(routes, ")|(") + ")");
    if (regex_match(var, sm2, disjunction, regex_constants::match_not_null)) {
        for (size_t index = 1; index < sm2.size(); ++index) {
            if (sm2[index].length() > 0) {
                std::cout << "Capture group index: " << index - 1 << std::endl;
                std::cout << var << " matched route " << routes[index - 1]
                          << std::endl;
                break;
            }
        }
    }

    return 0;
}
