#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs.is_open())
        return;

    ofs << "      /\\" << std::endl;
    ofs << "     /*\\" << std::endl;
    ofs << "    /**\\" << std::endl;
    ofs << "   /***\\" << std::endl;
    ofs << "  /****\\" << std::endl;
    ofs << "      | |" << std::endl;
    ofs.close();
}