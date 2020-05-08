#include <iostream>
#include "time.h"

int main() {
    int day = 1;
    Time time(23, 58, 58);
    for (int i = 0; i < 200; i += 1) {
        std::cout << "2019-10-" << day << " ";
        time.print_standard();
        if (time.tick()) {
            day += 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
