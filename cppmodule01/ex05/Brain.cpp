#include "Brain.hpp"

Brain::Brain()
{
	
}

Brain::Brain(int lifetime)
{
	this->years = lifetime;
}

std::string Brain::identify()
{
	std::stringstream str;
	str << this;
	return (str.str());
}

