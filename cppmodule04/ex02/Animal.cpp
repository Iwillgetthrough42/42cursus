#include "Animal.hpp"

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal()
{
	std::cout << "Animal default constructor" << std::endl;
	this->type = "";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal(Animal const &other)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = other;
}

Animal& Animal::operator=(Animal const &other)
{
	
	this->type = other.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}