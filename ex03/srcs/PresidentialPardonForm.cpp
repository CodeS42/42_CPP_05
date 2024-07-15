#include "../headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon form", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called." << std::endl;
    setTarget("Default");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon form", 25, 5)
{
    std::cout << "PresidentialPardonForm constructor called." << std::endl;
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
    if (this != &other)
    {
        setIsSigned(other.getIsSigned());
        setTarget(other.getTarget());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    else
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
