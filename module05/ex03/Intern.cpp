#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string&) = {
        [](const std::string& target) { return new ShrubberyCreationForm(target); },
        [](const std::string& target) { return new RobotomyRequestForm(target); },
        [](const std::string& target) { return new PresidentialPardonForm(target); }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}
