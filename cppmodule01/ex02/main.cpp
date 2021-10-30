#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

std::string randomStr()
{
	std::string s;
	char str[] = "abcdefghijklmnopqrstuwhij";

	for(int i = 0; i < 5; i++)
	{
		s += str[rand() % (sizeof(str) - 1)];
	}
	return (s);
}

int main()
{
	ZombieEvent ze;
	ze.setZombieType("SoulEater");
	Zombie *z = ze.newZombie("Ninja");
	z->announce();
	delete z;

	ze.setZombieType("random chump");
	ze.randomChump();
}