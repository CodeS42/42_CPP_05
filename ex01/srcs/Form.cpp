#include "../headers/Form.hpp"

Form::Form() : name("Default"), is_signed(false), grade_to_sign(30), grade_to_execute(10)
{
    std::cout << "Form default constructor called." << std::endl;
    checkGrades();
}

Form::Form(std::string name, int sign, int execute) : name(name), is_signed(false), grade_to_sign(sign), grade_to_execute(execute)
{
    std::cout << "Form constructor called." << std::endl;
    checkGrades();
}

Form::Form(const Form& obj) : name(obj.getName()), grade_to_sign(obj.getGradeToSign()), grade_to_execute(obj.getGradeToExecute())
{
    std::cout << "Form copy constructor called." << std::endl;
    *this = obj;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form assignment operator called." << std::endl;
    if (this != &other)
        is_signed = other.getIsSigned();
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called." << std::endl;
}

void Form::checkGrades(void) const
{
    if (getGradeToExecute() < 1 || getGradeToSign() < 1)
		throw GradeTooHighException();
	else if (getGradeToExecute() > 150 || getGradeToSign() > 150)
		throw GradeTooLowException();
}

std::string Form::getName(void) const
{
    return (name);
}

bool Form::getIsSigned(void) const
{
    return (is_signed);
}

int Form::getGradeToSign(void) const
{
    return (grade_to_sign);
}

int Form::getGradeToExecute(void) const
{
    return (grade_to_execute);
}

void Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    else
        is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    std::string signed_or_not;

    if (obj.getIsSigned())
        signed_or_not = "Signed";
    else
        signed_or_not = "Not signed";

    os << obj.getName() << ":" << std::endl;
    os << signed_or_not << std::endl;
    os << "Grade required to sign it: " << obj.getGradeToSign() << std::endl;
    os << "Grade required to execute it: " << obj.getGradeToExecute() << std::endl;

    return (os);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high!");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low!");
}
