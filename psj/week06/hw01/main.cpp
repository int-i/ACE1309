#include <iostream>
#include "date.h"

int main() {
    Date date1;
    Date date2(284, 2019);
    Date date3(11, 10, 2019);
    Date date4("October", 11, 2019);

    date1.print();
    std::cout << std::endl;

    date2.print_dddyyyy();
    std::cout << std::endl;

    date3.print_mmddyy();
    std::cout << std::endl;

    date4.print_monthddyyyy();
    std::cout << std::endl;

    return 0;
}