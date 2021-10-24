#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact()
{

}

void Contact::Add()
{
	std::cout << "input name ";
	std:: getline(std::cin, fields.name);
	std::cout << "input last name ";
	std:: getline(std::cin, fields.lastName);
	std::cout << "input nickname ";
	std:: getline(std::cin, fields.nickName);
	std::cout << "input phone number ";
	std:: getline(std::cin, fields.phoneNum);
	std::cout << "input darkest secret ";
	std:: getline(std::cin, fields.secret);
}

std::string Contact::printable(std::string str)
{
	if (str.length() <= 10)
		return (str);
	str = str.substr(0, 9);
	str.append(".");
	return (str);
}

void Contact::print()
{
	std::cout << std::setw(10) << printable(fields.name);
	std::cout << " | ";
	std::cout << std::setw(10) << printable(fields.lastName);
	std::cout << " | ";
	std::cout << std::setw(10) << printable(fields.nickName);
	std::cout << " | " << std::endl;
}

void Contact::printAll()
{
	std::cout << "name: " + fields.name << std::endl;
	std::cout << "last name: " + fields.lastName << std::endl;
	std::cout << "nickname: " + fields.nickName << std::endl;
	std::cout << "phonenum: " + fields.phoneNum << std::endl;
	std::cout << "darkest secret: " + fields.secret << std::endl;
}

Contact::~Contact()
{

}
