#include "../headers/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& obj)
{
    std::cout << "Intern constructor called." << std::endl;
    (void) obj;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern assignment operator called." << std::endl;
    (void) other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string names[] = { "Presidential pardon form",
                            "Robotomy request form",
                            "Shrubbery creation form" };
    AForm* (*create_forms[]) (std::string) = { &makePresidentialPardonForm,
                                               &makeRobotomyRequestForm,
                                               &makeShrubberyCreationForm };

    for (int i = 0 ; i < 3 ; i++)
    {
        if (names[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return ((*create_forms[i])(target));
        }
    }
    std::cout << "Intern can't create " << name  << " because this form doesn't exist." << std::endl;

    return (NULL);
}
