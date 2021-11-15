#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b;
		b.dec();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}