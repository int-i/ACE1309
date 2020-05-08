#include <iostream>
#include "time.h"

using std::cout;
using std::endl;

int main() {
    Time time(23, 59, 57);
    for (int i = 0; i < 18; i += 1) {
        if (i < 9) {
            time.print_standard();
        } else {
            time.print_universal();
        }
        time.tick();
        cout << endl;
    }
    return 0;
}
