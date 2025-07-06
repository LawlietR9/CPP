#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "=== Basic Form Test ===" << std::endl;
        Form form("Tax Form", 50, 25);
        std::cout << form << std::endl;

        Bureaucrat bob("Bob", 75);
        Bureaucrat alice("Alice", 45);

        std::cout << "\n=== Signing Attempt (Too Low Grade) ===" << std::endl;
        std::cout << bob << std::endl;
        bob.signForm(form);

        std::cout << "\n=== Signing Attempt (Sufficient Grade) ===" << std::endl;
        std::cout << alice << std::endl;
        alice.signForm(form);
        std::cout << form << std::endl;

        std::cout << "\n=== Invalid Form Creation Attempt ===" << std::endl;
        Form invalidForm("Invalid", 0, 25); // Should throw exception
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Another Invalid Form Creation ===" << std::endl;
        Form invalidForm("Invalid", 50, 151); // Should throw exception
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Multiple Signing Attempts ===" << std::endl;
        Form complexForm("Complex Form", 30, 15);
        std::cout << complexForm << std::endl;

        Bureaucrat chief("Chief", 1);
        Bureaucrat intern("Intern", 150);

        std::cout << "\nIntern's attempt:" << std::endl;
        intern.signForm(complexForm);

        std::cout << "\nChief's attempt:" << std::endl;
        chief.signForm(complexForm);
        
        std::cout << "\nFinal form state:" << std::endl;
        std::cout << complexForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}