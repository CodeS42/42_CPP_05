#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request form", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
    setTarget("Default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45)
{
    std::cout << "RobotomyRequestForm constructor called." << std::endl;
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
    *this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
    if (this != &other)
    {
        setIsSigned(other.getIsSigned());
        setTarget(other.getTarget());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    else
    {
        if (std::rand() % 2 == 0)
            std::cout << getTarget() << " has been robotomized successfully." << std::endl;
        else
            std::cout << "The robotomy failed." << std::endl;
    }
}
