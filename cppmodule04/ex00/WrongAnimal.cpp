#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "hiiii  " << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}