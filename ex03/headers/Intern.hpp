#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& obj);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm* makeForm(std::string name, std::string target);
        static AForm* makePresidentialPardonForm(std::string target);
        static AForm* makeRobotomyRequestForm(std::string target);
        static AForm* makeShrubberyCreationForm(std::string target);
};

#endif
