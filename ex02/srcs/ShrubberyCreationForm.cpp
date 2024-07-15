#include "../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation form", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
    setTarget("Default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation form", 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor called." << std::endl;
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
    *this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
    if (this != &other)
    {
        setIsSigned(other.getIsSigned());
        setTarget(other.getTarget());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    else
    {
        std::string fileName = getTarget();
        fileName.append("_shrubbery");
        std::ofstream file(fileName.c_str());

        if (!file.is_open())
        {
            std::cerr << "Failed to open file." << std::endl;
            std::exit(1);
        }

        file << "      _---_" << std::endl;
        file << "   /~~     ~~\\" << std::endl;
        file << " (~~         ~~)" << std::endl;
        file << "{               }" << std::endl;
        file << "  \\ _-     -_ /" << std::endl;
        file << "   ~  \\   /  ~" << std::endl;
        file << " _- -  | | _- _" << std::endl;
        file << "   _ - | |   -_" << std::endl;
        file << "       / \\" << std::endl;

        file.close();
    }
}
