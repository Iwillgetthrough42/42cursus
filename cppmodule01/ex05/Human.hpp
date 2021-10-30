#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human
{
	public:
		Human();
		std::string identify();
		Brain &getBrain();
	private:
		Brain brain;
};

#endif