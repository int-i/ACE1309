#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template<typename T>
void cast_vector(const std::vector<std::string> strings, std::vector<T>& vector) {
    std::transform(strings.begin(), strings.end(), std::back_inserter(vector), [](const std::string& string) {
        std::stringstream parser(string);
        T t;
        parser >> t;
        if (!parser.fail()) {
            return t;
        } else {
            throw 1;
        }
    });
}

template<typename T>
void print_vector(const std::vector<T>& vector) {
    for (const T& element : vector) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

void split(const std::string& string, std::vector<std::string>& vector) {
    std::istringstream line(string);
    std::string ss;
    while (std::getline(line, ss, ' ')) {
        vector.push_back(ss);
    }
}

int main() {
    while (true) {
        std::cout << "Data items in original order" << std::endl;
        std::vector<std::string> strings;
        std::string line;
        std::getline(std::cin, line);
        split(line, strings);
        try {
            std::vector<double> doubles;
            cast_vector<double>(strings, doubles);
            std::cout << "Data items in ascending order" << std::endl;
            std::sort(doubles.begin(), doubles.end());
            print_vector(doubles);
        } catch (int e) {
            try {
                std::vector<char> chars;
                cast_vector<char>(strings, chars);
                std::cout << "Data items in ascending order" << std::endl;
                std::sort(chars.begin(), chars.end());
                print_vector(chars);
            } catch (int e) {
                std::cout << "Error: cannot cast the vector element" << std::endl;
            }
        }
    }
    return 0;
}
