#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
class Form;
#include <string>

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
		void virtual action();
		std::string getTarget() const;
		void setTarget(std::string const target);
};

#endif