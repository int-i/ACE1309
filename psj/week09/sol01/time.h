#ifndef ACE1309_WEEK09_SOL01_TIME_H
#define ACE1309_WEEK09_SOL01_TIME_H

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int = 0, int = 0, int = 0);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    void print_standard() const;
    void print_universal() const;
    void set_hour(int);
    void set_minute(int);
    void set_second(int);
    void set_time(int, int, int);
    bool tick();
};

#endif // ACE1309_WEEK09_SOL01_TIME_H
