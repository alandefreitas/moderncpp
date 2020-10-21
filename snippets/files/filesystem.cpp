#include CXX_FILESYSTEM_HEADER
#include <fstream>
#include <iostream>
#include <string>

int main() {
    using namespace std;

    namespace fs = CXX_FILESYSTEM_NAMESPACE;

    // Writing to file
    ofstream fout;
    fout.open("example.txt");
    if (fout.is_open()) {
        fout << "This is a line.\n";
        fout << "This is another line.\n";
        fout.close();
    }

    // Reading from file
    string line;
    ifstream fin("example.txt");
    if (fin.is_open()) {
        while (getline(fin, line)) {
            cout << line << '\n';
        }
        fin.close();
    }

    // Describing paths
    fs::path p1{"C:\\"};
    fs::path p2{"C:\\Windows"};
    fs::path p3{L"C:\\Boost C++ \u5E93"};
    cout << "p2.string(): " << p2.string() << '\n';
    cout << "p2.generic_string(): " << p2.generic_string() << '\n';

    // Portable path
    fs::path root_p{"/"};
    cout << "root_p.string(): " << root_p.string() << '\n';
    cout << "root_p.generic_string(): " << root_p.generic_string() << '\n';

    // Path components
    fs::path p{"C:\\Windows\\System\\photo.jpg"};
    cout << "p.root_name(): " << p.root_name() << '\n';
    cout << "p.root_directory(): " << p.root_directory() << '\n';
    cout << "p.root_path(): " << p.root_path() << '\n';
    cout << "p.relative_path(): " << p.relative_path() << '\n';
    cout << "p.parent_path(): " << p.parent_path() << '\n';
    cout << "p.filename(): " << p.filename() << '\n';
    cout << "p.stem(): " << p.stem() << '\n';
    cout << "p.extension(): " << p.extension() << '\n';

    fs::path pl{"/Linux/System/photo.jpg"};
    cout << "pl: " << pl << '\n';
    cout << "pl.lexically_proximate(\"/Linux/\"): "
         << pl.lexically_proximate("/Linux/") << '\n';
    cout << "pl.root_name(): " << pl.root_name() << '\n';
    cout << "pl.root_directory(): " << pl.root_directory() << '\n';
    cout << "pl.root_path(): " << pl.root_path() << '\n';
    cout << "pl.relative_path(): " << pl.relative_path() << '\n';
    cout << "pl.parent_path(): " << pl.parent_path() << '\n';
    cout << "pl.filename(): " << pl.filename() << '\n';
    cout << "pl.stem(): " << pl.stem() << '\n';
    cout << "pl.extension(): " << pl.extension() << '\n';

    fs::path p4{"C:\\Windows\\System\\photo.jpg"};
    for (const fs::path &pp : p4) {
        cout << pp << endl;
    }

    fs::path p5{"/Linux/System/photo.jpg"};
    for (const fs::path &pp : p5) {
        cout << pp << endl;
    }

    fs::path p6{"/"};
    p6 /= "Linux/System";
    for (const fs::path &pp : p6) {
        cout << pp << endl;
    }

    // Files and Directories:
    // Testing if it's directory
    fs::path p7{"/"};
    try {
        fs::file_status s = status(p7);
        cout << boolalpha << fs::is_directory(s) << '\n';
    } catch (fs::filesystem_error &e) {
        cerr << e.what() << '\n';
    }

    // File size
    fs::path p8{"C:\\Windows\\win.ini"};
    error_code ec;
    size_t filesize = fs::file_size(p8, ec);
    if (!ec) {
        cout << filesize << '\n';
    } else {
        cout << ec << '\n';
    }

    // Last time write
    fs::path p9{"C:\\Windows\\win.ini"};
    try {
        fs::file_time_type t = last_write_time(p9);
        std::time_t cftime = fs::file_time_type::clock::to_time_t(t);
        cout << cftime << '\n';
    } catch (fs::filesystem_error &e) {
        cout << e.what() << '\n';
    }

    // Retrieve total and remaining disk space
    fs::path p10{"/"};
    try {
        fs::space_info s = space(p10);
        cout << "s.capacity: " << s.capacity << " bytes" << endl;
        cout << "s.free: " << s.free << " bytes" << endl;
        cout << "s.available: " << s.available << " bytes" << endl;
    } catch (fs::filesystem_error &e) {
        cerr << e.what() << '\n';
    }

    // Creating, renaming, and deleting directories
    fs::path p11 = fs::current_path();
    p /= "test_directory";
    try {
        if (create_directory(p11)) {
            fs::path p12 = fs::current_path();
            p12 /= "test_directory2";
            rename(p, p12);
            fs::remove(p12);
        } else {
            cout << "The path could not be created" << endl;
        }
    } catch (fs::filesystem_error &e) {
        cerr << e.what() << '\n';
    }

    // absolute path based on a file name
    try {
        cout << fs::absolute("photo.jpg") << '\n';
    } catch (fs::filesystem_error &e) {
        cerr << e.what() << '\n';
    }

    // Directory Iterators
    // Iterating over files
    fs::path p13 = fs::current_path();
    fs::directory_iterator range{p13};
    for (auto &p : range) {
        cout << p.path().filename() << '\n';
    }

    // Recursively iterating over files
    fs::path p14 = fs::current_path();
    fs::recursive_directory_iterator it{p14};
    while (it != fs::recursive_directory_iterator{}) {
        cout << it->path().lexically_proximate(fs::current_path()) << '\n';
        ++it;
    }

    // File Streams from paths
    // Streaming to files
    fs::path p15 = fs::absolute("example_text.txt");
    ofstream ofs{p15};
    ofs << "Hello, world!\n";
    ofs << "Bye, world!\n";

    return 0;
}