#include "ZombieEvent.hpp"

void  	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(this->type, name);
	return (zombie);
}

void ZombieEvent::randomChump()
{
	Zombie z(this->type, randomStr());
	z.announce();
}

std::string ZombieEvent::getType() const
{
	return (this->type);
}

ZombieEvent::ZombieEvent()
{

}