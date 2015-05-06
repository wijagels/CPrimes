#include "cprimes.h"

int main() {
    unsigned long long int a;
    std::cout << "Maximum number: " << ULLONG_MAX << std::endl;
    std::vector<unsigned long long int>();
    std::string line;
    while(true) {
        std::cout << "Please enter a number: " << std::endl;
        while(std::getline(std::cin, line)) {
            if(line == "exit") {
                break;
            }
            std::string::size_type sz;
            a = std::stoi(line, &sz);
            std::cout << a << std::endl;
        }
    }
}
