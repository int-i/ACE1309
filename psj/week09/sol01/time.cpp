#include "time.h"
#include <iomanip>
#include <iostream>

using std::cout;
using std::setfill;
using std::setw;

Time::Time(int h, int m, int s) {
    set_time(h, m, s);
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
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

void Time::print_universal() const {
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << minute << ":"
         << setfill('0') << setw(2) << second;
}

void Time::set_hour(int h) {
    hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::set_minute(int m) {
    minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::set_second(int s) {
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::set_time(int h, int m, int s) {
    set_hour(h);
    set_minute(m);
    set_second(s);
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
