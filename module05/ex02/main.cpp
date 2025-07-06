#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford");

        std::cout << "--- Testing ShrubberyCreationForm ---" << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
        alice.executeForm(shrub);

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        bob.signForm(robot);
        bob.executeForm(robot);

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        bob.signForm(pardon);
        bob.executeForm(pardon);

        std::cout << "\n--- Testing Unsigned Form ---" << std::endl;
        ShrubberyCreationForm shrub2("garden");
        bob.executeForm(shrub2);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}