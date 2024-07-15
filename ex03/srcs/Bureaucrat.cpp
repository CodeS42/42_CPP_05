#include "../headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	std::cout << "Bureaucrat defalut constructor called." << std::endl;
	setGrade(75);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat constructor called." << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName())
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	if (this != &other)
		setGrade(other.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

void Bureaucrat::incrementGrade(void)
{
	setGrade(grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	setGrade(grade + 1);
}

const std::string Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

void Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
	}
	catch (std::exception &e)
	{
        std::cerr << getName() << " couldn't signed " << obj.getName() << " because " << e.what() << std::endl;
	}
	if (obj.getIsSigned())
    	std::cout << getName() << " signed " << obj.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << getName() << " executed " << form.getName() << std::endl;
}
