#include "Human.hpp"

Human::Human()
{

}

std::string Human::identify()
{
	return (brain.identify());
}

Brain &Human::getBrain()
{
	return (brain);
}