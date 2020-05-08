#ifndef ACE1309_WEEK05_HW01_TIME_H
#define ACE1309_WEEK05_HW01_TIME_H

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int hour = 0, int minute = 0, int second = 0);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    void print_standard() const;
    void print_universal() const;
    void set_hour(int hour);
    void set_minute(int minute);
    void set_second(int second);
    void set_time(int hour, int minute, int second);
    bool tick();
};

#endif // ACE1309_WEEK05_HW01_TIME_H
