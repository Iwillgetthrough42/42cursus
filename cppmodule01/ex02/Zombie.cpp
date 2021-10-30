#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string type, std::string name)
{
	this->type = type;
	this->name = name;
}

Zombie::Zombie()
{
	this->type = "";
	this->name = "";
}

void Zombie::announce()
{
	std::cout << "< " + this->name + " " + this->type + " > Brainsssss" << std::endl;
}

std::string Zombie::getName() const
{
	return (this->name);
}

std::string Zombie::getType() const
{
	return (this->type);
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::setType(std::string type)
{
	this->type = type;
}