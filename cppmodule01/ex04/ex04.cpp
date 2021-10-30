#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *str1 = &str;
	std::string &str2 = str;

	std::cout << "with pointer - " + *str1 << std::endl;
	std::cout << "with refference - " + str2 << std::endl;
}