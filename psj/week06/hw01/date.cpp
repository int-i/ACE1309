#include "date.h"
#include <ctime>
#include <iomanip>
#include <iostream>

const std::string mnames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() {
    std::time_t now = std::time(0);
    std::tm* ltm = std::localtime(&now);
    year = ltm->tm_year + 1900;
    month = ltm->tm_mon + 1;
    day = ltm->tm_mday;
}

Date::Date(int ddd, int yyyy) {
    year = check_year(yyyy);
    set_mmdd_from_ddd(ddd);
}

Date::Date(int dd, int mm, int yyyy) {
    year = check_year(yyyy);
    month = check_month(mm);
    day = check_day(dd);
}

Date::Date(std::string month, int dd, int yyyy) {
    year = check_year(yyyy);
    set_mm_from_month(month);
    day = check_day(dd);
}

int Date::check_day(int dd) const {
    if (dd >= 1 && dd <= days_in_month(month)) {
        return dd;
    } else {
        std::cout << "Invalid day (" << dd << ") sets to 1." << std::endl;
        return 1;
    }
}

int Date::check_month(int mm) const {
    if (mm >= 1 && mm <= 12) {
        return mm;
    } else {
        std::cout << "Invalid month (" << mm << ") sets to 1." << std::endl;
        return 1;
    }
}

int Date::check_year(int yyyy) const {
    if (yyyy >= 0) {
        return yyyy;
    } else {
        std::cout << "Invalid year (" << yyyy << ") sets to 1900." << std::endl;
        return 1900;
    }
}

int Date::convert_dd_to_ddd() const {
    int ddd = 0;
    for (int mm = 1; mm < month; mm += 1) {
        ddd += days_in_month(mm);
    }
    ddd += day;
    return ddd;
}

std::string Date::convert_mm_to_month() const {
    return mnames[month - 1];
}

int Date::convert_yyyy_to_yy() const {
    return year % 100;
}

int Date::days_in_month(int mm) const {
    return mm == 2 ? (is_leap_year() ? 29 : 28) : mdays[mm - 1];
}

bool Date::is_leap_year() const {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void Date::set_mmdd_from_ddd(int ddd) {
    int mm = 1;
    while (ddd > days_in_month(mm)) {
        ddd -= days_in_month(mm);
        mm += 1;
    }
    month = mm;
    day = ddd;
}

void Date::set_mm_from_month(std::string month) {
    for (int mm = 1; mm <= 12; mm += 1) {
        if (month == mnames[mm - 1]) {
            this->month = mm;
            return;
        }
    }
    std::cout << "Invalid month (" << month << ") sets to 1." << std::endl;
    this->month = 1;
}

void Date::set_yyyy_from_yy(int yy) {
    if (yy >= 0 && yy <= 99) {
        year = (yy > 50 ? 1900 : 2000) + yy;
    } else {
        std::cout << "Invalid year (" << yy << ") sets to 1900." << std::endl;
        year = 1900;
    }
}

void Date::print() const {
    std::cout << month << "/"
              << day << "/"
              << year;
}

void Date::print_dddyyyy() const {
    std::cout << std::setfill('0') << std::setw(3) << convert_dd_to_ddd() << " "
              << year;
}

void Date::print_mmddyy() const {
    std::cout << std::setfill('0') << std::setw(2) << month << "/"
              << std::setfill('0') << std::setw(2) << day << "/"
              << convert_yyyy_to_yy();
}

void Date::print_monthddyyyy() const {
    std::cout << convert_mm_to_month() << " "
              << std::setfill('0') << std::setw(2) << day << ", "
              << year;
}

void Date::set_day(int dd) {
    day = check_day(dd);
}

void Date::set_month(int mm) {
    month = check_month(mm);
}

void Date::set_year(int yyyy) {
    year = check_year(yyyy);
}
