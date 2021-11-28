#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> intarray(10);
		for (int i = 0; i < intarray.getlength(); i++)
		{
			intarray[i] = i;
		}
		for (int i = 0; i < intarray.getlength(); i++)
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