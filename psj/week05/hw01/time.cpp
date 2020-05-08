#include "time.h"
#include <iomanip>
#include <iostream>

Time::Time(int hour, int minute, int second) {
    set_time(hour, minute, second);
}

int Time::get_hour() const {
    return hour;
}

int Time::get_minute() const {
    return minute;
}

int Time::get_second() const {
    return second;
}

void Time::print_standard() const {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setfill('0') << std::setw(2) << second << (hour < 12 ? " AM" : " PM");
}

void Time::print_universal() const {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setfill('0') << std::setw(2) << minute << ":"
              << std::setfill('0') << std::setw(2) << second;
}

void Time::set_hour(int hour) {
    this->hour = (hour >= 0 && hour < 24) ? hour : 0;
}

void Time::set_minute(int minute) {
    this->minute = (minute >= 0 && minute < 60) ? minute : 0;
}

void Time::set_second(int second) {
    this->second = (second >= 0 && second < 60) ? second : 0;
}

void Time::set_time(int hour, int minute, int second) {
    set_hour(hour);
    set_minute(minute);
    set_second(second);
}

bool Time::tick() {
    set_second(second + 1);
    if (second == 0) {
        set_minute(minute + 1);
        if (minute == 0) {
            set_hour(hour + 1);
            return hour == 0;
        }
    }
    return false;
}
