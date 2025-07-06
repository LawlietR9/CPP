#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            Bureaucrat bob("Bob", 1);
            bob.signForm(*rrf);
            bob.executeForm(*rrf);
            delete rrf;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n------------------\n" << std::endl;

    try {
        rrf = someRandomIntern.makeForm("presidential pardon", "Ford");
        if (rrf)
        {
            Bureaucrat jim("Jim", 4);
            jim.signForm(*rrf);
            jim.executeForm(*rrf);
            delete rrf;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n------------------\n" << std::endl;

    try {
        rrf = someRandomIntern.makeForm("unknown form", "Anyone");
        if (rrf)
        {
            delete rrf;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}