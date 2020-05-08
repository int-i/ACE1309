#ifndef ACE1309_WEEK06_HW01_DATE_H
#define ACE1309_WEEK06_HW01_DATE_H

#include <string>

class Date {
private:
    int year;
    int month;
    int day;
    int check_day(int dd) const;
    int check_month(int mm) const;
    int check_year(int yyyy) const;
    int convert_dd_to_ddd() const;
    std::string convert_mm_to_month() const;
    int convert_yyyy_to_yy() const;
    int days_in_month(int mm) const;
    bool is_leap_year() const;
    void set_mmdd_from_ddd(int ddd);
    void set_mm_from_month(std::string month);
    void set_yyyy_from_yy(int yy);

public:
    Date();
    Date(int ddd, int yyyy);
    Date(int dd, int mm, int yyyy);
    Date(std::string month, int dd, int yyyy);
    void print() const;
    void print_dddyyyy() const;
    void print_mmddyy() const;
    void print_monthddyyyy() const;
    void set_day(int dd);
    void set_month(int mm);
    void set_year(int yyyy);
};

#endif // ACE1309_WEEK06_HW01_DATE_H
