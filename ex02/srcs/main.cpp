#include "../headers/Bureaucrat.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat a("Charlie", 6);
	PresidentialPardonForm b("Charles Dupuis");
	RobotomyRequestForm c("Something");
	ShrubberyCreationForm d("Home");

	std::cout << a << std::endl;
	
	// Sign a Presidential pardon form
	try
	{
		a.signForm(b);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Try to execute it with a grade that is too low
	a.executeForm(b);
	// Increment the grade to be able to execute it
	try
	{
		a.incrementGrade();
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	// Execute the Presidential pardon form
	a.executeForm(b);
	
	// Try to execute a Robotomy request form that is not signed
	a.executeForm(c);
	// Sign it
	try
	{
		a.signForm(c);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Execute it two times to show that the robotomy success 50% of the time
	a.executeForm(c);
	a.executeForm(c);

	// Sign and execute a Shrubbery creation form
	try
	{
		a.signForm(d);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	a.executeForm(d);

	return (0);
}