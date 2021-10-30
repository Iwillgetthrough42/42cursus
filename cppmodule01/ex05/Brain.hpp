#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <sstream>

class Brain
{
	public:
		Brain(int lifetime);
		Brain();
		std::string identify();
	private:
		int years;
};


#endif