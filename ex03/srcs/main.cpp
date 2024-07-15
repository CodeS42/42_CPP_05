#include "../headers/Bureaucrat.hpp"
#include "../headers/Intern.hpp"

int main(void)
{
	Intern a;
	Bureaucrat b = Bureaucrat("Charlie", 6);
	AForm *forms[] = { a.makeForm("Presidential pardon form", "Shane Cook"),
					   a.makeForm("Robotomy request form", "Bender"),
					   a.makeForm("Shrubbery creation form", "Garden"),
					   a.makeForm("Smile form", "something") };

	std::cout << b << std::endl;
	
	// Sign a Presidential pardon form
	try
	{
		b.signForm(*forms[0]);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Try to execute it with a grade that is too low
	b.executeForm(*forms[0]);
	// Increment the grade to be able to execute it
	try
	{
		b.incrementGrade();
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	// Execute the Presidential pardon form
	b.executeForm(*forms[0]);
	
	// Try to execute a Robotomy request form that is not signed
	b.executeForm(*forms[1]);
	// Sign it
	try
	{
		b.signForm(*forms[1]);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Execute it two times to show that the robotomy success 50% of the time
	b.executeForm(*forms[1]);
	b.executeForm(*forms[1]);

	// Sign and execute a Shrubbery creation form
	try
	{
		b.signForm(*forms[2]);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	b.executeForm(*forms[2]);

	// Try to sign and execute a form that doesn't exist
	try
	{
		if (forms[3])
			b.signForm(*forms[3]);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (forms[3])
		b.executeForm(*forms[3]);

	for (int i = 0 ; i < 4 ; i++)
		delete forms[i];

	return (0);
}
