#include "Phonebook.class.hpp"

Phonebook::Phonebook()
{
	this->index = 0;
}

Phonebook::~Phonebook()
{

}

void Phonebook::fillContact()
{
	contacts[index % 8].Add();
	index++;
}

void Phonebook::search()
{
	int i;
	std::cout << "input index to find" << std::endl;
	std::cin >> i;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	if (std::cin.fail())
	{
		std::cout << "you've entered wrong imput";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (i > index || i > 8 || i < 1)
	{
		std::cout << "index is not valid" << std::endl;
		return ;
	}
	contacts[(i - 1) % 8].printAll();
}

void Phonebook::printInfo()
{
	std::cout << std::setw(10) << contacts[0].printable("Number");
	std::cout << " | ";
	std::cout << std::setw(10) << contacts[0].printable("First Name");
	std::cout << " | ";
	std::cout << std::setw(10) << contacts[0].printable("Last Name");
	std::cout << " | ";
	std::cout << std::setw(10) << contacts[0].printable("Nick Name");
	std::cout << " | " << std::endl;
	for (int i = 0; i < index; i++)
	{
		if (i >= 8)
			return ;
		std::cout << std::setw(10) << i + 1;
		std::cout << " | ";
		contacts[i % 8].print();
	}
}