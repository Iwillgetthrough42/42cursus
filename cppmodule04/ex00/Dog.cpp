#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(Dog const &other) : Animal("Dog")
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	
	this->type = other.type;
	return (*this);
}


void Dog::makeSound() const
{
	std::cout << "dog's sound" << std::endl;
}