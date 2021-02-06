#include <date/date.h>
#include <date/tz.h>
#include <iostream>

int main() {
    // date.h contains chrono extensions to deal with dates
    // It has been incorporated into
    // References:
    // - https://howardhinnant.github.io/date/date.html
    // - https://howardhinnant.github.io/date/tz.html
    using namespace std;
    using namespace std::chrono;

    // Printing time points
    // - UTC time zone and microsecond precision
    using date::operator<<;
    const std::chrono::time_point now = system_clock::now();
    std::cout << "Now: " << now << std::endl;
    std::cout << "Formatted: "
              << date::format("%a, %b %d, %Y at %I:%M %p %Z", now) << '\n';
    std::cout << date::format(std::locale("de_DE"), "%a, %b %d, %Y at %T %Z",
                              now)
              << '\n';

    cout << "Epoch: " << time_point<system_clock>(seconds(0)) << endl;

    // Days since 1970 represented as one integer
    // - This is a serial-based time-point
    // - Good for day oriented arithmetic
    date::sys_days today = date::floor<date::days>(now);
    cout << "today: " << today.time_since_epoch().count() << " days since epoch"
         << endl;

    // Days since 1970 represented as 3 integers: year / month / day
    // - This is a field-based time-point
    // - Good for returning field values
    // - Good for month/year arithmetic
    // Last day of March / 2015
    using namespace date::literals;
    date::year_month_day t_ymd = 2015_y / date::March / 22;
    std::cout << "t_ymd: " << t_ymd << std::endl;
    std::cout << "t_ymd since epoch: "
              << date::sys_days(t_ymd).time_since_epoch().count() << std::endl;

    // Days since 1970 represented as 4 integers: year / month / week / weekday
    // This is a field-based time-point
    date::year_month_weekday t_ymw =
        date::year{2015} / date::month{3} / date::Monday[2];
    std::cout << "t_ymw: " << t_ymw << std::endl;
    std::cout << "t_ymw since epoch: "
              << date::sys_days(t_ymw).time_since_epoch().count() << std::endl;
    std::cout << "year_month_day(t3): "
              << date::sys_days(date::year_month_day(t_ymw))
                     .time_since_epoch()
                     .count()
              << std::endl;

    // Converting to/from year/month/date
    auto today_ymd = date::year_month_day{today};
    cout << "Today is " << today_ymd << '\n';

    // Durations
    // - Time since midnight (serial-based)
    auto time_since_midnight = now - today;
    cout << "Serial time since midnight "
         << duration_cast<seconds>(time_since_midnight) << '\n';

    // - Time since midnight (field-based)
    date::hh_mm_ss time_since_midnight_hms(time_since_midnight);
    cout << "Field-based time since midnight: " << today_ymd << " - "
         << time_since_midnight_hms << endl;

    auto time_since_midnight_tod = date::make_time(time_since_midnight);
    cout << "Field-based time since midnight: " << today_ymd << " - "
         << time_since_midnight_tod << endl;

    // Checking invalid field based dates
    // - It's possible and it might be useful
    cout << "All odd fridays this year: ";
    date::year this_year = today_ymd.year();
    for (auto m = 1; m <= 12; ++m) {
        auto first_friday =
            date::year_month_day(this_year / m / date::Friday[1]);
        cout << first_friday << ' ';
        auto third_friday = first_friday.year() / first_friday.month() /
                            (first_friday.day() + weeks{2});
        cout << third_friday << ' ';
        auto fifth_friday = third_friday.year() / third_friday.month() /
                            (third_friday.day() + weeks{2});
        if (fifth_friday.ok()) {
            cout << fifth_friday << ' ';
        }
    }
    std::cout << std::endl;

    // Dealing with time zones
    // - Zoned time is a wrapper that also keeps track of the shift from UTC
    date::zoned_time local_tp = date::make_zoned(date::current_zone(), now);

    // - Little more efficient way. Less convenient unless reusing the zone ptr.
    auto berlin_zone = date::locate_zone("Europe/Berlin");
    auto berlin_time =
        date::make_zoned(berlin_zone, floor<seconds>(system_clock::now()));
    std::cout << "berlin time: "
              << date::format(std::locale("de_DE"), "%a, %b %d, %Y at %T %Z",
                              berlin_time)
              << '\n';

    // - Little less efficient way. More convenient.
    auto sp_time = date::make_zoned("America/Sao_Paulo",
                                    floor<seconds>(system_clock::now()));
    std::cout << "sao paulo time: "
              << date::format(std::locale("de_DE"), "%a, %b %d, %Y at %T %Z",
                              sp_time)
              << '\n';

    // Time zone details
    std::cout << "local_tp: " << local_tp << std::endl;
    std::cout << "offset: " << local_tp.get_info().offset << std::endl;
    std::cout << "save: " << local_tp.get_info().save << std::endl;
    std::cout << "abbrev: " << local_tp.get_info().abbrev << std::endl;
    std::cout << "Local time: " << local_tp.get_local_time() << std::endl;
    std::cout << "Sys time: " << local_tp.get_sys_time() << std::endl;
    std::cout << "Formatted: "
              << date::format("%a, %b %d, %Y at %I:%M %p %Z", local_tp) << '\n';
    std::cout << date::format(std::locale("de_DE"), "%a, %b %d, %Y at %T %Z",
                              local_tp)
              << '\n';

    // Change precision
    auto now_nanoseconds = date::floor<nanoseconds>(now);
    auto local_tp_nanoseconds =
        date::make_zoned(date::current_zone(), now_nanoseconds);
    std::cout << "In millisecs: " << local_tp_nanoseconds << std::endl;

    auto now_milliseconds = date::floor<milliseconds>(now);
    auto local_tp_milliseconds =
        date::make_zoned(date::current_zone(), now_milliseconds);
    std::cout << "In millisecs: " << local_tp_milliseconds << std::endl;

    auto now_seconds = date::floor<seconds>(now);
    auto local_tp_seconds = date::make_zoned(date::current_zone(), now_seconds);
    std::cout << "In secs: " << local_tp_seconds << std::endl;

    auto now_hours = date::floor<hours>(now);
    auto local_tp_hours = date::make_zoned(date::current_zone(), now_hours);
    std::cout << "In hours: " << local_tp_hours << std::endl;

    auto now_days = date::floor<days>(now);
    auto local_tp_days = date::make_zoned(date::current_zone(), now_days);
    std::cout << "In days: " << local_tp_days << std::endl;

    // Convert time between zones
    auto tokyo_tp = date::make_zoned("Asia/Tokyo", sp_time);
    std::cout << sp_time << " in sao paulo is " << tokyo_tp << " in tokyo"
              << std::endl;

    return 0;
}
