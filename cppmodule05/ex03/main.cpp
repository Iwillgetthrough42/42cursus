#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat b("ben", 20);
		Intern intern;
		Form *f = intern.makeForm("RobotomyRequestForm", "lll");
		std::cout << *f << std::endl;
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}