#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> intarray(10);
		for (int i = 0; i < 10; i++)
		{
			intarray[i] = i;
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << intarray[i] << std::endl;
		}
		intarray[20];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}