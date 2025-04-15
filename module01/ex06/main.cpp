#include "Harl.hpp"

int main() {
    Harl harl;
    while (true) {
        std::string level;
        std::cout << "Enter a level (DEBUG, INFO, WARNING, ERROR): ";
        std::cin >> level;
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
        harl.complain(level);
    }
    return 0;
}