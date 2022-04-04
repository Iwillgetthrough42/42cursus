#include "ScavTrap.hpp"


int main()
{
	ScavTrap scav("lol");
	ScavTrap sc(scav);
	scav.attack("coucou");
	scav.takeDamage(3);
	scav.beRepaired(2);
	
}
