#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

Contact::Contact()
{

}

void Contact::setdata(std::string name, std::string lastName, std::string\
			nickName, std::string phoneNum, std::string secret)
{
	this->fields.name = name;
	this->fields.lastName = lastName;
	this->fields.nickName = nickName;
	this->fields.phoneNum = phoneNum;
	this->fields.secret = secret;
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
