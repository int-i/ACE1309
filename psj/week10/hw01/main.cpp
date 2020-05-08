#include <iostream>
#include <string>

const std::string operator+(const std::string& lhs, const std::string& rhs) {
    return lhs + ' ' + rhs;
}

int main() {
    std::string string1("happy");
    std::string string2("birthday");
    std::string string3 = string1 + string2;

    std::cout << "string1: " << string1 << std::endl
              << "string2: " << string2 << std::endl
              << "string3: " << string3 << std::endl
              << std::endl;

    std::string string4("happy");
    std::string string5("birth day");
    std::string string6("to you");
    std::string string7 = string4 + string5 + string6;

    std::cout << "string4: " << string4 << std::endl
              << "string5: " << string5 << std::endl
              << "string6: " << string6 << std::endl
              << "string7: " << string7 << std::endl;
    return 0;
}
