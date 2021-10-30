#include "ZombieHorde.hpp"

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
	ZombieHorde horde(5);
	horde.announce();

	return (0);
}