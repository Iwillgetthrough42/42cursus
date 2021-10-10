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
	std::cout << "input login ";
	std:: getline(std::cin, fields.login);
	std::cout << "input postal code ";
	std:: getline(std::cin, fields.postal);
	std::cout << "input email ";
	std:: getline(std::cin, fields.email);
	std::cout << "input phonenum ";
	std:: getline(std::cin, fields.phoneNum);
	std::cout << "input birthday ";
	std:: getline(std::cin, fields.birthday);
	std::cout << "input favorite meal ";
	std:: getline(std::cin, fields.meal);
	std::cout << "input underwear color ";
	std:: getline(std::cin, fields.underwCol);
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
	std::cout << "login: " + fields.login << std::endl;
	std::cout << "postal code: " + fields.postal << std::endl;
	std::cout << "email: " + fields.email << std::endl;
	std::cout << "phonenum: " + fields.phoneNum << std::endl;
	std::cout << "birthday: " + fields.birthday << std::endl;
	std::cout << "favorite meal: " + fields.meal << std::endl;
	std::cout << "underwear color: " + fields.underwCol << std::endl;
	std::cout << "darkest secret: " + fields.secret << std::endl;
}

Contact::~Contact()
{

}
