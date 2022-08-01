#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Copy constructor dog" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog assignment operator" << std::endl;
	this->type = other.type;
	Brain *tmp = this->brain;
	this->brain = new Brain(*other.brain);
	delete (tmp);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "dog's sound" << std::endl;
}

Brain &Dog::getBrain() const
{
	return (*this->brain);
}