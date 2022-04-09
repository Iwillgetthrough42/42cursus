#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "Form.hpp"
class Form;
#include <string>

class PresidentialPardonForm : public Form
{	
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm &other);
		std::string getTarget() const;
		void setTarget(std::string const target);
		void virtual action();
};


#endif