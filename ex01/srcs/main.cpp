#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

int main(void)
{
	Bureaucrat a("Charlie", 51);
	Form b("Employment contract", 50, 20);

	// Try to create a Form with a grade that is too high
	try 
	{
		Form too_high("TooHighForm", 0, 100);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Try to create a Form with a grade that is too low
	try 
	{
		Form too_low("TooLowForm", 1, 160);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b;

	// Try to sign a form with a grade that is too low
	try
	{
		a.signForm(b);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Increment the grade to be able to sign the Form
	try
	{
		a.incrementGrade();
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	
	// Sign the Form
	try
	{
		a.signForm(b);
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << b;

	return (0);
}