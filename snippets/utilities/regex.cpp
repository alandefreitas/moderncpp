#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    if (regex_match("subject", regex("(sub)(.*)"))) {
        cout << "match" << endl;
    }

    const char cstr[] = "subject";
    string s("subject");
    regex e("(sub)(.*)");

    if (regex_match(s, e)) {
        cout << "match" << endl;
    }

    if (regex_match(s.begin(), s.end(), e)) {
        cout << "match" << endl;
    }

    // same as match_results<const char*> cm;
    cmatch cm;
    regex_match(cstr, cm, e);
    cout << "literal string with " << cm.size() << " matches" << endl;

    // same as match_results<string::const_iterator> sm;
    smatch sm;
    regex_match(s, sm, e);
    cout << "string object with " << sm.size() << " matches" << endl;

    regex_match(s.cbegin(), s.cend(), sm, e);
    cout << sm.size() << " matches" << endl;

    // Using flgas
    regex_match(cstr, cm, e, regex_constants::match_default);

    cout << "The matches were: ";
    for (unsigned i = 0; i < sm.size(); ++i) {
        cout << "[" << sm[i] << "] ";
    }
    cout << endl;

    return 0;
}
