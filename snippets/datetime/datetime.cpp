//[headers Headers
#include <date/date.h>
#include <date/tz.h>
//]
#include <iostream>
#include <version>

int main() {
    //[enable Enable operator<< for time points
    // Ensure operator<< it's not ambiguous with C++20 datetime
#if !defined(__cpp_lib_chrono) || __cpp_lib_chrono < 201907L
    using date::operator<<;
#endif
    //]

    {
        using date::operator<<;
        //[print Printing time points
        // - UTC time zone and microsecond precision
        const std::chrono::time_point now = std::chrono::system_clock::now();
        std::cout << "Now: " << now << '\n';
        //]
    }

    const std::chrono::time_point now = std::chrono::system_clock::now();
    //[print_formatted Print formatted time points
    std::cout << "Formatted: "
              << date::format("%a, %b %d, %Y at %I:%M %p %Z", now) << '\n';
    //]

    //[print_locale Print formatted time points in time zone
    {
        using date::operator<<;
        std::cout << date::format(std::locale("de_DE"),
                                  "%a, %b %d, %Y at %T %Z", now)
                  << '\n';
    }
    //]

    {
        using date::operator<<;
        //[print_epoch Print Epoch
        std::cout << "Epoch: "
                  << std::chrono::time_point<std::chrono::system_clock>(
                         std::chrono::seconds(0))
                  << '\n';
        //]
    }

    //[sys_days Days since 1970 represented as a single integer
    // - This is a serial-based time-point
    // - Good for day oriented arithmetic
    date::sys_days today = date::floor<date::days>(now);
    std::cout << "today: " << today.time_since_epoch().count()
              << " days since epoch" << '\n';
    //]

    //[ymd_date Days since 1970 represented as 3 integers: year / month / day
    // - This is a field-based time-point
    // - Good for returning field values
    // - Good for month/year arithmetic
    // Last day of March / 2015
    using namespace date::literals;
    date::year_month_day t_ymd = 2015_y / date::March / 22;
    std::cout << "t_ymd: " << t_ymd << '\n';
    std::cout << "t_ymd since epoch: "
              << date::sys_days(t_ymd).time_since_epoch().count() << '\n';
    //]

    //[ymw_date Days since 1970 represented as 4 integers: year / month / week /
    // weekday
    // This is a field-based time-point
    date::year_month_weekday t_ymw =
        date::year{2015} / date::month{3} / date::Monday[2];
    std::cout << "t_ymw: " << t_ymw << '\n';
    std::cout << "t_ymw since epoch: "
              << date::sys_days(t_ymw).time_since_epoch().count() << '\n';
    std::cout << "year_month_day(t3): "
              << date::sys_days(date::year_month_day(t_ymw))
                     .time_since_epoch()
                     .count()
              << '\n';
    //]

    //[convert Converting to/from year/month/date
    auto today_ymd = date::year_month_day{today};
    std::cout << "Today is " << today_ymd << '\n';
    //]

    //[durations Durations
    // - Time since midnight (serial-based)
    auto time_since_midnight = now - today;
    std::cout << "Serial time since midnight "
              << duration_cast<std::chrono::seconds>(time_since_midnight)
              << '\n';
    //]

    //[dur_field Time since midnight (field-based)
    date::hh_mm_ss time_since_midnight_hms(time_since_midnight);
    std::cout << "Field-based time since midnight: " << today_ymd << " - "
              << time_since_midnight_hms << '\n';
    //]

    //[dur_field_2 Time since midnight (field-based)
    auto time_since_midnight_tod = date::make_time(time_since_midnight);
    std::cout << "Field-based time since midnight: " << today_ymd << " - "
              << time_since_midnight_tod << '\n';
    //]

    //[invalid_field_based Checking invalid field based dates
    // They are possible, and they might be even useful
    std::cout << "All odd fridays this year: ";
    date::year this_year = today_ymd.year();
    for (auto m = 1; m <= 12; ++m) {
        auto first_friday =
            date::year_month_day(this_year / m / date::Friday[1]);
        std::cout << first_friday << ' ';
        auto third_friday = first_friday.year() / first_friday.month() /
                            (first_friday.day() + date::weeks{2});
        std::cout << third_friday << ' ';
        auto fifth_friday = third_friday.year() / third_friday.month() /
                            (third_friday.day() + date::weeks{2});
        if (fifth_friday.ok()) {
            std::cout << fifth_friday << ' ';
        }
    }
    std::cout << '\n';
    //]

    // Course dates example - all wednesdays and fridays in a range
    auto class_start = 2021_y / date::May / 26;
    auto class_end = 2021_y / date::August / 20;
    while (class_start <= class_end) {
        // Class date
        date::year_month_weekday class_start_ymw(class_start);
        if (class_start_ymw.weekday() == date::Wednesday) {
            std::cout << class_start.day() << '/' << class_start.month() << '/'
                      << class_start.year() << " - Teórica - \n";
        } else {
            std::cout << class_start.day() << '/' << class_start.month() << '/'
                      << class_start.year() << " - Prática - \n";
        }
        if (class_start_ymw.weekday() == date::Wednesday) {
            // Move to Friday
            class_start = date::sys_days(class_start) + date::days{2};
        } else if (class_start_ymw.weekday() == date::Friday) {
            // Move to next Wednesday
            class_start = date::sys_days(class_start) + date::days{5};
        }
    }

    //[timezone Dealing with time zones
    // Zoned time is a wrapper that also keeps track of the shift from UTC
    date::zoned_time local_tp = date::make_zoned(date::current_zone(), now);
    //]

    //[zone_ptr Zone pointers
    // Little more efficient. Less convenient unless reusing the zone ptr.
    auto berlin_zone = date::locate_zone("Europe/Berlin");
    auto berlin_time = date::make_zoned(
        berlin_zone,
        floor<std::chrono::seconds>(std::chrono::system_clock::now()));
    std::cout << "berlin time: "
              << date::format(std::locale("de_DE"), "%a, %b %d, %Y at %T %Z",
                              berlin_time)
              << '\n';
    //]

    //[no_zone_ptr Make zoned time
    // Little less efficient. More convenient.
    auto sp_time = date::make_zoned(
        "America/Sao_Paulo",
        floor<std::chrono::seconds>(std::chrono::system_clock::now()));
    std::cout << "sao paulo time: "
              << date::format(std::locale("de_DE"), "%a, %b %d, %Y at %T %Z",
                              sp_time)
              << '\n';
    //]

    {
        {
            using date::operator<<;
            //[tz_details Time zone details
            std::cout << "local_tp: " << local_tp << '\n';
            std::cout << "abbrev: " << local_tp.get_info().abbrev << '\n';
            std::cout << "Sys time: " << local_tp.get_sys_time() << '\n';
            //]
        }
        //[tz_details_conv Convert zoned time point
        std::cout << "offset: " << local_tp.get_info().offset << '\n';
        std::cout << "save: " << local_tp.get_info().save << '\n';
        std::cout << "Local time: " << local_tp.get_local_time() << '\n';
        //]
        {
            using date::operator<<;
            //[tz_details_format Format zoned time point
            std::cout << "Formatted: "
                      << date::format("%a, %b %d, %Y at %I:%M %p %Z", local_tp)
                      << '\n';
            std::cout << date::format(std::locale("de_DE"),
                                      "%a, %b %d, %Y at %T %Z", local_tp)
                      << '\n';
            //]
        }
        //]
    }

    //[precision Change precision
    auto now_nanoseconds = date::floor<std::chrono::nanoseconds>(now);
    auto local_tp_nanoseconds =
        date::make_zoned(date::current_zone(), now_nanoseconds);
    std::cout << "In millisecs: " << local_tp_nanoseconds << '\n';
    //]

    //[precision_milli Change precision to milliseconds
    auto now_milliseconds = date::floor<std::chrono::milliseconds>(now);
    auto local_tp_milliseconds =
        date::make_zoned(date::current_zone(), now_milliseconds);
    std::cout << "In millisecs: " << local_tp_milliseconds << '\n';
    //]

    //[precision_milli Change precision to seconds
    auto now_seconds = date::floor<std::chrono::seconds>(now);
    auto local_tp_seconds = date::make_zoned(date::current_zone(), now_seconds);
    std::cout << "In secs: " << local_tp_seconds << '\n';
    //]

    //[precision_milli Change precision to hours
    auto now_hours = date::floor<std::chrono::hours>(now);
    auto local_tp_hours = date::make_zoned(date::current_zone(), now_hours);
    std::cout << "In hours: " << local_tp_hours << '\n';
    //]

    //[precision_milli Change precision to days
    auto now_days = date::floor<date::days>(now);
    auto local_tp_days = date::make_zoned(date::current_zone(), now_days);
    std::cout << "In days: " << local_tp_days << '\n';
    //]

    //[convert_zones Convert time between zones
    auto tokyo_tp = date::make_zoned("Asia/Tokyo", sp_time);
    std::cout << sp_time << " in sao paulo is " << tokyo_tp << " in tokyo"
              << '\n';
    //]

    return 0;
}
