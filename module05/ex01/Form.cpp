#include "Form.hpp"

// Orthodox Canonical Form
Form::Form() 
    : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        const_cast<std::string&>(_name) = other._name;
        _signed = other._signed;
        const_cast<int&>(_gradeToSign) = other._gradeToSign;
        const_cast<int&>(_gradeToExecute) = other._gradeToExecute;
    }
    return *this;
}

Form::~Form() {}

// Getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// Exception classes
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName()
       << " (sign grade: " << form.getGradeToSign()
       << ", execute grade: " << form.getGradeToExecute()
       << ", signed: " << (form.isSigned() ? "yes" : "no") << ")";
    return os;
}