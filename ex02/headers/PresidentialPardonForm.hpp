#ifndef PRESIDENTIAL_PARON_FORM_HPP
# define PRESIDENTIAL_PARON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void execute(Bureaucrat const& executor) const;
};

#endif
