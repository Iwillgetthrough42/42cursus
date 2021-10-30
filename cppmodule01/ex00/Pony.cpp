#include "Pony.hpp"
#include <iostream>

Pony::Pony(int level)
{
	this->speedLevel = level;
}

void Pony::run()
{
	std::cout << "Hi I'm Pony have a nice trip" << std::endl;
}

void Pony::eat()
{
	std::cout << "I'm hungryyy" << std::endl;
}

int Pony::getlevel() const
{
	return (this->speedLevel);
}

void Pony::setlevel(int level)
{
	if (level >= 0)
		this->speedLevel = level;
}

void Pony::train()
{
	this->speedLevel++;
	std::cout << "my level became " << this->speedLevel << std::endl;
}

