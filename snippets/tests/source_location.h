//
// Created by Alan Freitas on 17/11/20.
//

#ifndef MODERNCPP_SOURCE_LOCATION_H
#define MODERNCPP_SOURCE_LOCATION_H

namespace std {
    class source_location {
    public:
        [[nodiscard]] static constexpr auto current(
#if defined(__has_builtin) && __has_builtin(__builtin_FILE) && __has_builtin(__builtin_LINE)
                const char* file = __builtin_FILE(), int line = __builtin_LINE()
#else
                const char *file = "unknown", int line = {}
#endif
        ) noexcept {
            source_location sl{};
            sl.file_ = file;
            sl.line_ = line;
            return sl;
        }

        [[nodiscard]] constexpr auto file_name() const noexcept { return file_; }

        [[nodiscard]] constexpr auto line() const noexcept { return line_; }

    private:
        const char *file_{"unknown"};
        int line_{};
    };
}


#endif // MODERNCPP_SOURCE_LOCATION_H
