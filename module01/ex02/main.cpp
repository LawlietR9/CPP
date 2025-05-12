#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* ptr = &str;
    std::string& ref = str;

    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << ptr << std::endl;
    std::cout << "Memory address held by stringREF: " << &ref << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *ptr << std::endl;
    std::cout << "Value pointed to by stringREF: " << ref << std::endl;

    return 0;
}