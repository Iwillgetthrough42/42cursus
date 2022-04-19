#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	
}

Intern::~Intern()
{

}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void) other;
	return (*this);	
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string types[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};
	Form *forms[3] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target),
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == types[i])
		{
			for (int j = 0; j < 3 && types[j] != types[i]; j++){ delete forms[j];};
			std::cout << "Intern creates form " << name << std::endl;
			return (forms[i]);
		}
	}
	std::cout << "Intern couldn't create a form" << std::endl;
	return (NULL);

}