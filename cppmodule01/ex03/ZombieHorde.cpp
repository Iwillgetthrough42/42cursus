#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	this->count = n;
	this->z = new Zombie[this->count];
	for (int i = 0; i < n; i++)
	{
		z[i].setName(randomStr());
		z[i].setType("from horde");
	}
}

void ZombieHorde::announce()
{
	for (int i = 0; i < this->count; i++)
	{
		z[i].announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->z;
}