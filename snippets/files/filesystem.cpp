//[headers Include headers found by CMake
#include CXX_FILESYSTEM_HEADER
//]
#include <fstream>
#include <iostream>
#include <string>

int main() {
    //[namespace_fs Define `fs` as the namespace for the filesystem library
    namespace fs = CXX_FILESYSTEM_NAMESPACE;
    //]

    //[write Writing to file
    std::ofstream fout;
    fout.open("example.txt");
    if (fout.is_open()) {
        fout << "This is a line.\n";
        fout << "This is another line.\n";
        fout.close();
    }
    //]

    //[read Reading from file
    std::string line;
    std::ifstream fin("example.txt");
    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::cout << line << '\n';
        }
        fin.close();
    }
    //]

    //[paths Describing paths
    fs::path p1{"C:\\"};
    fs::path p2{"C:\\Windows"};
    fs::path p3{L"C:\\Boost C++ \u5E93"};
    std::cout << "p2.string(): " << p2.string() << '\n';
    std::cout << "p2.generic_string(): " << p2.generic_string() << '\n';
    //]

    //[portable Portable paths
    fs::path root_p{"/"};
    std::cout << "root_p.string(): " << root_p.string() << '\n';
    std::cout << "root_p.generic_string(): " << root_p.generic_string() << '\n';
    //]

    //[path_components Path components
    fs::path p{"C:\\Windows\\System\\photo.jpg"};
    std::cout << "p.root_name(): " << p.root_name() << '\n';
    std::cout << "p.root_directory(): " << p.root_directory() << '\n';
    std::cout << "p.root_path(): " << p.root_path() << '\n';
    std::cout << "p.relative_path(): " << p.relative_path() << '\n';
    std::cout << "p.parent_path(): " << p.parent_path() << '\n';
    std::cout << "p.filename(): " << p.filename() << '\n';
    std::cout << "p.stem(): " << p.stem() << '\n';
    std::cout << "p.extension(): " << p.extension() << '\n';
    //]

    //[relative Relative paths
    fs::path pl{"/Linux/System/photo.jpg"};
    std::cout << "pl: " << pl << '\n';
    std::cout << "pl.lexically_proximate(\"/Linux/\"): "
         << pl.lexically_proximate("/Linux/") << '\n';
    std::cout << "pl.root_name(): " << pl.root_name() << '\n';
    std::cout << "pl.root_directory(): " << pl.root_directory() << '\n';
    std::cout << "pl.root_path(): " << pl.root_path() << '\n';
    std::cout << "pl.relative_path(): " << pl.relative_path() << '\n';
    std::cout << "pl.parent_path(): " << pl.parent_path() << '\n';
    std::cout << "pl.filename(): " << pl.filename() << '\n';
    std::cout << "pl.stem(): " << pl.stem() << '\n';
    std::cout << "pl.extension(): " << pl.extension() << '\n';
    //]

    //[iterate Iterate Path components
    fs::path p4{"C:\\Windows\\System\\photo.jpg"};
    for (const fs::path &pp : p4) {
        std::cout << pp << '\n';
    }
    //]

    //[iterate2 Iterate Path components
    fs::path p5{"/Linux/System/photo.jpg"};
    for (const fs::path &pp : p5) {
        std::cout << pp << '\n';
    }
    //]

    //[concat Concatenate paths
    fs::path p6{"/"};
    p6 /= "Linux/System";
    for (const fs::path &pp : p6) {
        std::cout << pp << '\n';
    }
    //]

    //[files_and_dirs Files and Directories
    fs::path p7{"/"};
    try {
        fs::file_status s = status(p7);
        std::cout << std::boolalpha << fs::is_directory(s) << '\n';
    } catch (fs::filesystem_error const &e) {
        std::cerr << e.what() << '\n';
    }
    //]

    //[file_size File size
    fs::path p8{"C:\\Windows\\win.ini"};
    std::error_code ec;
    size_t filesize = fs::file_size(p8, ec);
    if (!ec) {
        std::cout << filesize << '\n';
    } else {
        std::cout << ec << '\n';
    }
    //]

    //[last_write Last time write
    fs::path p9{"C:\\Windows\\win.ini"};
    try {
        // Maybe unused as an example, because the next code snippet
        // is not portable
        fs::file_time_type t = last_write_time(p9);
        /* The following is not portable:
         * https://en.cppreference.com/w/cpp/filesystem/file_time_type
        std::time_t cftime = fs::file_time_type::clock::to_time_t(t);
        std::cout << cftime << '\n';
         */
        (void) t; // t is unused because the previous snippet is not portable
    } catch (fs::filesystem_error &e) {
        std::cout << e.what() << '\n';
    }
    //]

    //[disk Retrieve total and remaining disk space
    fs::path p10{"/"};
    try {
        fs::space_info s = space(p10);
        std::cout << "s.capacity: " << s.capacity << " bytes" << '\n';
        std::cout << "s.free: " << s.free << " bytes" << '\n';
        std::cout << "s.available: " << s.available << " bytes" << '\n';
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << '\n';
    }
    //]

    //[create_dirs Creating, renaming, and deleting directories
    fs::path p11 = fs::current_path();
    p /= "test_directory";
    try {
        if (create_directory(p11)) {
            fs::path p12 = fs::current_path();
            p12 /= "test_directory2";
            rename(p, p12);
            fs::remove(p12);
        } else {
            std::cout << "The path could not be created" << '\n';
        }
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << '\n';
    }
    //]

    //[absolute absolute path based on a file name
    try {
        std::cout << fs::absolute("photo.jpg") << '\n';
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << '\n';
    }
    //]

    //[dir_iter Iterating over directory files
    fs::path p13 = fs::current_path();
    fs::directory_iterator range{p13};
    for (auto &dir_p : range) {
        std::cout << dir_p.path().filename() << '\n';
    }
    //]

    //[dir_iter Recursively iterating over files
    fs::path p14 = fs::current_path();
    fs::recursive_directory_iterator it{p14};
    while (it != fs::recursive_directory_iterator{}) {
        std::cout << it->path().lexically_proximate(fs::current_path()) << '\n';
        ++it;
    }
    //]

    //[ofstream_fs File Streams from paths
    fs::path p15 = fs::absolute("example_text.txt");
    std::ofstream ofs{p15};
    ofs << "Hello, world!\n";
    ofs << "Bye, world!\n";
    //]

    return 0;
}