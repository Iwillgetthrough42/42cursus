#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Constructor cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(Cat const &other) : Animal("Cat")
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	
	this->type = other.type;
	return (*this);
}


void Cat::makeSound() const
{
	std::cout << "cat's sound" << std::endl;
}

