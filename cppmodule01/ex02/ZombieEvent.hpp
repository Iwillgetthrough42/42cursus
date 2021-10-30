#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <string>
#include "Zombie.hpp"
std::string randomStr();

class ZombieEvent
{
	public:
		void 	setZombieType(std::string type);
		Zombie 	*newZombie(std::string name);
		void 	randomChump();
		ZombieEvent();
		std::string getType() const;
	private:
		std::string type;
};

#endif