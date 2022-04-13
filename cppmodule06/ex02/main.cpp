#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate()
{
	srand(time(NULL));
	switch(rand() % 3)
	{
		case 0:	return (new A());
		case 1:	return (new B());
		case 2:	return (new C());
		default: return (NULL);
	}
}


void identify(Base* p)
{
	A *tmp;
	B *tm;
	C *t;

	if ((tmp = dynamic_cast<A *>(p)) != NULL)
		std::cout << "Type of p pointer is A" << std::endl;
	else if ((tm = dynamic_cast<B *>(p)) != NULL)
	{
		std::cout << "Type of p pointer is B" << std::endl;
	}
	else if ((t = dynamic_cast<C *>(p)) != NULL)
	{
		std::cout << "Type of p pointer is C" << std::endl;
	}
}

void identify(Base &p)
{
	try
	{
		p = dynamic_cast<A &>(p);
		std::cout << "type of p is A" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		p = dynamic_cast<B &>(p);
		std::cout << "type of p is B" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		p = dynamic_cast<C &>(p);
		std::cout << "type of p is A" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	Base *p = generate();
	identify(p);
	identify(*p);

}