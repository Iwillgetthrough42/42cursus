#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("ben", 70);
		PresidentialPardonForm f("f1");
		ShrubberyCreationForm sh("f2");
		RobotomyRequestForm r("f3");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
		b.signForm(sh);
		b.executeForm(sh);
		b.signForm(r);
		b.executeForm(r);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}