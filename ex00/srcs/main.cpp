#include "../headers/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a;

	// Decrement the grade of a Bureaucrat
	std::cout << a << std::endl;
	try
	{
		a.decrementGrade();
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;

	// Try to create a Bureaucrat with a grade that is too high
	try 
	{
		Bureaucrat too_high("TooHighMan", 0);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Try to create a Bureaucrat with a grade that is too low
	try 
	{
		Bureaucrat too_low("TooLowMan", 151);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Try to increment the grade of a bureaucrat who is already at the highest grade
	Bureaucrat c("Billie", 1);
	try
	{
		c.incrementGrade();
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << c << std::endl;

	// Try to decrement the grade of a bureaucrat who is already at the lowest grade
	Bureaucrat d("Paul", 150);
	try
	{
		d.decrementGrade();
	}	
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << d << std::endl;

	return (0);
}