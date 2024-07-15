#include "../headers/AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), grade_to_sign(30), grade_to_execute(10)
{
    std::cout << "AForm default constructor called." << std::endl;
    checkGrades();
}

AForm::AForm(std::string name, int sign, int execute) : name(name), is_signed(false), grade_to_sign(sign), grade_to_execute(execute)
{
    std::cout << "AForm constructor called." << std::endl;
    checkGrades();
}

AForm::AForm(const AForm& obj) : name(obj.getName()), grade_to_sign(obj.getGradeToSign()), grade_to_execute(obj.getGradeToExecute())
{
    std::cout << "AForm copy constructor called." << std::endl;
    *this = obj;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm assignment operator called." << std::endl;
    if (this != &other)
        is_signed = other.getIsSigned();
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm destructor called." << std::endl;
}

void AForm::checkGrades(void) const
{
    if (getGradeToExecute() < 1 || getGradeToSign() < 1)
		throw GradeTooHighException();
	else if (getGradeToExecute() > 150 || getGradeToSign() > 150)
		throw GradeTooLowException();
}

std::string AForm::getName(void) const
{
    return (name);
}

bool AForm::getIsSigned(void) const
{
    return (is_signed);
}

int AForm::getGradeToSign(void) const
{
    return (grade_to_sign);
}

int AForm::getGradeToExecute(void) const
{
    return (grade_to_execute);
}

void AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    else
        is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    std::string signed_or_not;

    if (obj.getIsSigned())
        signed_or_not = "Signed";
    else
        signed_or_not = "Not signed";

    os << obj.getName() << ":" << std::endl;
    os << "Target : " << obj.getTarget() << std::endl;
    os << signed_or_not << std::endl;
    os << "Grade required to sign it: " << obj.getGradeToSign() << std::endl;
    os << "Grade required to execute it: " << obj.getGradeToExecute() << std::endl;

    return (os);
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high!");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low!");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
}

void AForm::setTarget(std::string target)
{
    this->target = target;
}

std::string AForm::getTarget(void) const
{
    return (target);
}

void AForm::setIsSigned(bool signed_or_not)
{
    is_signed = signed_or_not;
}
