#include <iostream>
#include <sstream>
#include <string>
//[headers Headers
#include <regex>
//]

int main() {
    //[match Match single expression
    if (std::regex_match("subject", std::regex("(sub)(.*)"))) {
        std::cout << "subject matches expression (sub)(.*)" << '\n';
    }
    //]

    //[match_string Match string
    const char cstr[] = "subject";
    std::string s("subject");
    std::regex e("(sub)(.*)");
    if (regex_match(s, e)) {
        std::cout << "subject matches expression (sub)(.*)" << '\n';
    }
    //]

    //[match_range Match char range
    if (std::regex_match(s.begin(), s.end(), e)) {
        std::cout << "subject matches expression (sub)(.*)" << '\n';
    }
    //]

    //[match_result Store match results
    std::cmatch cm; // same as `match_results<const char*>`
    std::regex_match(cstr, cm, e);
    //]

    //[match_result_inspect Access match results
    std::cout << "literal string with " << cm.size() << " matches" << '\n';
    std::cout << "The literal string matches were: ";
    for (const auto &i : cm) {
        std::cout << "[" << i << "] ";
    }
    std::cout << '\n';
    //]

    //[match_result_string Store string match results
    std::smatch sm; // match_results<string::const_iterator>
    std::regex_match(s, sm, e);
    //]

    //[match_result_inspect_string Access string match results
    std::cout << "string object with " << sm.size() << " matches" << '\n';
    std::cout << "The string matches were: ";
    for (const auto &i : sm) {
        std::cout << "[" << i << "] ";
    }
    std::cout << '\n';
    //]

    //[match_result_string Store char range match results
    regex_match(s.cbegin(), s.cend(), sm, e);
    std::cout << sm.size() << " matches" << '\n';
    //]

    //[flags Using flags to determine behavior
    std::regex_match(cstr, cm, e, std::regex_constants::match_default);
    //]

    //[iterate Iterate substrings with matches
    std::string ss = "foo bar 123";
    std::regex r("([a-zA-Z]+)|(d+)");
    std::sregex_iterator match_it(ss.begin(), ss.end(), r);
    for (; match_it != std::sregex_iterator(); ++match_it) {
        std::smatch m = *match_it;
        // Match
        std::cout << "Match value: " << m.str() << " at position "
                  << m.position() << '\n';
        // Groups
        for (size_t index = 1; index < m.size(); ++index) {
            if (!m[index].str().empty()) {
                std::cout << "Capture group ID: " << index - 1 << '\n';
                break;
            }
        }
    }
    //]

    //[concat Regex expression conjunction
    std::string var = "first second third forth";
    if (regex_match(var, sm, std::regex("(.*) (.*) (.*) (.*)"))) {
        for (size_t i = 1; i < sm.size(); i++) {
            std::cout << "Match " << i << ": " << sm[i] << " at position "
                      << sm.position(i) << '\n';
        }
    }
    //]

    //[implode Helper function to implode strings
    auto implode = [](const std::vector<std::string> &strs,
                      const std::string &delim) {
        std::stringstream s;
        copy(strs.begin(), strs.end(),
             std::ostream_iterator<std::string>(s, delim.c_str()));
        return s.str();
    };
    //]

    //[disjunction Regex expression string disjunction
    var = "user/32";
    std::smatch sm2;
    std::vector<std::string> routes = {"welcome", "user/\\d+", "post/[a-zA-Z]+",
                                       "about"};
    std::regex disjunction("(" + implode(routes, ")|(") + ")");
    //]

    //[match_disjunction Match disjunction
    if (std::regex_match(var, sm2, disjunction,
                         std::regex_constants::match_not_null)) {
        for (size_t index = 1; index < sm2.size(); ++index) {
            if (sm2[index].length() > 0) {
                std::cout << "Capture group index: " << index - 1 << '\n';
                std::cout << var << " matched route " << routes[index - 1]
                          << '\n';
                break;
            }
        }
    }
    //]

    return 0;
}
