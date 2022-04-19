#include "Phonebook.class.hpp"


void Add(Contact &ob)
{
	std::string name, lastName, nickName, phoneNum, secret;

	std::cout << "input name ";
	std:: getline(std::cin, name);
	std::cout << "input last name ";
	std:: getline(std::cin, lastName);
	std::cout << "input nickname ";
	std:: getline(std::cin, nickName);
	std::cout << "input phone number ";
	std:: getline(std::cin, phoneNum);
	std::cout << "input darkest secret ";
	std:: getline(std::cin, secret);
	ob.setdata(name, lastName, nickName, phoneNum, secret);
}

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
	Phonebook phonebook;

	std :: cout << "\033[33m WELCOME TO PHONEBOOK" << std::endl;
	std::cout << "\033[0m" << std::endl;
	while (true)
	{
		std::getline(std::cin, str);
		str = upper(str);
		if (str == "ADD")
			phonebook.fillContact();
		else if (str == "EXIT")
			break ;
		else if (str == "SEARCH")
		{
			phonebook.printInfo();
			phonebook.search();
		}
		else if (str.length() != 0)
			std::cout << "TRY AGAIN" << std::endl;
	}
}