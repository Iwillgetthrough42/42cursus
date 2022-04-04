#include "FragTrap.hpp"

int main()
{
	FragTrap frag("lol");
	FragTrap fr(frag);
	fr.attack("coucou");
	fr.takeDamage(3);
	fr.beRepaired(2);
	fr.highFivesGuys();
	
}
