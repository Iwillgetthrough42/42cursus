#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Constructor cat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong cat's sound" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	
	this->type = other.type;
	return (*this);
}