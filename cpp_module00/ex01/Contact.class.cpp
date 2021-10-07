#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

std::string Contact::fields[11] = {
		"name",
		"last name",
		"nick name",
		"login",
		"postal",
		"email",
		"phone number",
		"birthday",
		"favorite meal",
		"underwear color",
		"darkest secret"
	};

Contact::Contact()
{
	this->index = 0;
}

void Contact::Add()
{
	if (index > 8)
	{
		std::cout << "more then 8 contacts";
		return ;
	}
	for (int i = 0; i < 11; i++)
	{
		std::cout << "input " + fields[i] + " ";
		std::getline(std::cin, vars[i][index]);
	}
	index++;
}

std::string Contact::printable(std::string str)
{
	if (str.length() <= 10)
		return (str);
	str = str.substr(0, 9);
	str.append(".");
	return (str);
}

void Contact::search(int i)
{
	if (i > index || i < 1)
	{
		std::cout << "index is not valid" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << printable(std::to_string(i));
	std::cout << " | ";
	for (int j = 0; j < 3; j++)
	{
		std::cout << std::setw(10) << printable(vars[j][i - 1]);
		std::cout << " | ";
	}
	std::cout << std::endl;

}

void Contact::print()
{
	std::cout << std::setw(10) << printable("Number");
	std::cout << " | ";
	for (int j = 0; j < 3; j++)
	{
		std::cout << std::setw(10) << printable(fields[j]);
		std::cout << " | ";
	}
	std::cout << std::endl;
	for (int i = 0; i < index; i++)
	{
		std::cout << std::setw(10) << printable(std::to_string(i + 1));
		std::cout << " | ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << std::setw(10) << printable(vars[j][i]);
			std::cout << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	int i;
	std::cout << "input index : ";
	std::cin >> i;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	if (std::cin.fail())
	{
		std::cout << "you've entered wrong imput";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	search(i);
}

Contact::~Contact()
{

}
