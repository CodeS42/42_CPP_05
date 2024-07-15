#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>
# include <cstdlib>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;
        std::string target;

    public:
        AForm();
        AForm(std::string name, int sign, int execute);
        AForm(const AForm& obj);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        void checkGrades(void) const;
        void beSigned(const Bureaucrat& obj);
        void setTarget(std::string target);
        std::string getTarget(void) const;
        void setIsSigned(bool signed_or_not);
        virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

    class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm& obj);

#endif
