#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

std::string	upper(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return (s);
}

int main()
{
	std::string str;
	Contact contact;

	std :: cout << "\033[33m WELCOME TO PHONEBOOK" << std::endl;
	std::cout << "\033[0m" << std::endl;
	while (true)
	{
		std::getline(std::cin, str);
		str = upper(str);
		if (str == "ADD")
			contact.Add();
		else if (str == "EXIT")
			break ;
		else if (str == "SEARCH")
			contact.print();
		else if (str.length() != 0)
			std::cout << "TRY AGAIN" << std::endl;
	}
}