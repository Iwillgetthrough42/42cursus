#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b("ben", 70);
		Form f("f1", false, 75, 140);
		std::cout << f << std::endl;
		b.signForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}