#include <iostream>
#include <sstream>
#include <string>
//[headers Headers
#include <lyra/lyra.hpp>
//]

int main(int argc, const char **argv) {
    {
        //[single Declare single option with default value `0`
        int width = 0;
        auto cli = lyra::cli() | lyra::opt(width, "width")["-w"]["--width"](
                                     "How wide should it be?");
        //]

        //[parse_single Parse single option
        auto result = cli.parse({argc, argv});
        //]

        result = cli.parse({"", "-w", "90"});

        //[check_single Check arguments
        if (!result) {
            std::cerr << "Error: " << result.message() << '\n';
            return 1;
        }
        //]

        //[use_single Use arguments
        std::cout << "width = " << width << "\n";
        //]
    }

    {
        //[multiple Declare multiple options with default values
        int width = 0;
        std::string name;
        bool do_it = false;

        auto cli = lyra::opt(width, "width")["-w"]["--width"](
                       "How wide should it be?") |
                   lyra::opt(name, "name")["-n"]["--name"](
                       "By what name should I be known") |
                   lyra::opt(do_it)["-d"]["--doit"]("Do the thing");
        //]

        auto result = cli.parse({"", "-w", "90", "--name", "Lyra"});

        if (result) {
            std::cout << "width = " << width << ", name = " << name
                      << ", do_it = " << do_it << "\n";
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[vector Vector options
        std::vector<std::string> names;
        auto cli = lyra::cli() | lyra::opt(names, "names")["-n"]["--names"](
                                     "What are your names?");
        //]

        auto result = cli.parse({"", "--names", "John", "--names", "Mary"});

        if (!result) {
            std::cerr << "Error: " << result.message() << '\n';
            return 1;
        }

        for (auto& n: names) {
            std::cout << "Hi, " << n << "!\n";
        }
    }

    {
        //[help Help option
        int width = 0;
        std::string name;
        bool do_it = false;
        bool show_help = false;

        auto cli = lyra::help(show_help) |
                   lyra::opt(width, "width")["-w"]["--width"](
                       "How wide should it be?") |
                   lyra::opt(name, "name")["-n"]["--name"](
                       "By what name should I be known") |
                   lyra::opt(do_it)["-d"]["--doit"]("Do the thing");
        //]

        auto result = cli.parse({"", "--help"});

        //[show_help Show help
        if (!result) {
            std::cerr << "Error: " << result.message() << '\n';
            std::cerr << cli << "\n";
            return 1;
        }
        if (show_help) {
            std::cout << cli << "\n";
        }
        //]

        if (result) {
            std::cout << width << '\n';
            std::cout << name << '\n';
            std::cout << do_it << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[explicit Explicit option specification
        int width = 0;
        auto cli =
            lyra::cli().add_argument(lyra::opt(width, "width")
                                         .name("-w")
                                         .name("--width")
                                         .help("How wide should it be?"));
        //]

        auto result = cli.parse({"", "-w", "90"});

        if (result) {
            std::cout << width << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[optional Optional argument
        int width = 0;
        auto cli = lyra::cli().add_argument(lyra::opt(width, "width")
                                                .name("-w")
                                                .name("--width")
                                                .help("How wide should it be?")
                                                .optional());
        //]

        auto result = cli.parse({"", "-w", "90"});

        if (result) {
            std::cout << width << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[required Required argument
        int width = 0;
        auto cli = lyra::cli().add_argument(lyra::opt(width, "width")
                                                .name("-w")
                                                .name("--width")
                                                .help("How wide should it be?")
                                                .required());
        //]

        auto result = cli.parse({"", "-w", "90"});

        if (result) {
            std::cout << width << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[choices Option choices
        std::string color;
        auto cli =
            lyra::cli().add_argument(lyra::opt(color, "color")
                                         .name("-c")
                                         .name("--color")
                                         .help("What color should it be?")
                                         .choices("red", "green", "blue"));
        //]

        auto result = cli.parse({"", "-c", "red"});

        if (result) {
            std::cout << color << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[choices Validate choice
        int width;
        auto cli = lyra::cli().add_argument(
            lyra::opt(width, "width")
                .name("-w")
                .name("--width")
                .help("What width should it be?")
                .choices([](int v) { return v % 2 == 0; }));
        //]

        auto result = cli.parse({"", "-w", "91"});

        if (result) {
            std::cout << width << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
    }

    {
        //[flags Counting flags
        int verbose = 0;
        auto plus_verbose = [&verbose](bool b) { verbose += b; };
        int flag = 0;
        auto plus_flag = [&verbose](bool b) { verbose += b; };
        auto cli = lyra::cli()
                       .add_argument(
                           lyra::opt(plus_verbose).name("-v").cardinality(0, 5))
                       .add_argument(
                           lyra::opt(plus_flag).name("-f").cardinality(0, 5));
        //]

        //[flags_show
        auto result = cli.parse({"", "-vvv"});
        if (result) {
            std::cout << verbose << '\n';
            std::cout << flag << '\n';
        } else {
            std::cerr << "Error: " << result.message() << '\n';
        }
        //]
    }

    {
        //[subcommand Sub-commands
        std::string command;
        bool show_help = false;
        bool show_run_help = false;
        auto run_callback = [&](const lyra::group &g) {
            if (show_run_help)
                std::cout << g;
            else
                std::cout << "Running\n";
        };

        auto cli =
            lyra::cli()
                .add_argument(lyra::help(show_help))
                .add_argument(lyra::command("run", run_callback)
                                  .help("Run the application.")
                                  .add_argument(lyra::help(show_run_help)));
        //]

        auto result = cli.parse({"", "run", "--help"});
        if (!result) {
            std::cerr << "Error: " << result.message() << '\n';
            std::cout << cli << '\n';
        }
    }

    {
        //[groups Argument groups
        // Group 1 (default group)
        bool show_full_screen = true;
        float aspect = 4.0f / 3.0f;

        // Group 2 (disables group 1)
        unsigned width = 0;
        unsigned height = 0;
        auto active_group_2 = [&](const lyra::group &) {
            show_full_screen = false;
        };

        // Main group
        bool get_help = false;

        auto cli =
            lyra::cli()
                .add_argument(lyra::help(get_help))
                .add_argument(lyra::opt(aspect, "aspect")
                                  .name("--aspect")
                                  .help("Full-screen aspect ratio window."))
                .add_argument(
                    lyra::group(active_group_2)
                        .add_argument(lyra::opt(width, "width")
                                          .required()
                                          .name("--width")
                                          .help("Width of window."))
                        .add_argument(lyra::opt(height, "height")
                                          .required()
                                          .name("--height")
                                          .help("Height of window.")));
        //]

        auto result = cli.parse({"", "--height", "90"});
        if (!result) {
            std::cerr << "Error: " << result.message() << '\n';
            std::cout << cli << '\n';
        }
    }

    {
        //[main Main CLI function
        int r = lyra::main()("-x", 0)("-y",
                                      0)("z", 5)(argc, argv, [](lyra::main &m) {
            std::cout << (int(m["-x"]) + int(m["-y"])) * int(m["z"]) << "\n";
            return 0;
        });
        //]
        std::cout << r << '\n';
    }

    {
        //[delimiter_style Define valid value delimiters
        int width = 0;
        auto cli = lyra::cli() | lyra::opt(width, "width")["-w"]["--width"](
                                     "How wide should it be?");
        cli.style({
            "=", // value delimiters
            "-", // long option prefix
            2,   // long option size
            "-", // short option prefix
            1    // short option size
        });
        //]

        auto result = cli.parse({argc, argv});
        if (result) {
            std::cout << "width = " << width << "\n";
        }
    }

    return 0;
}
