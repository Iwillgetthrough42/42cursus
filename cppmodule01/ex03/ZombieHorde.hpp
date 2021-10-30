#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

std::string randomStr();

class ZombieHorde
{
	public:
		ZombieHorde(int n);
		void announce();
		~ZombieHorde();
	private:
		Zombie *z;
		int count;
};

#endif