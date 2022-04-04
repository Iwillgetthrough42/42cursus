#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Scav Trap constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	*this = other;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &other)
{
	if (this == &other)
		return (*this);
	this->name = other.getName();
	this->hitPoints = other.getHitPoints();
	this->energyPoints = other.getEnergyPoints();
	this->attackDamage = other.getAttackDamage();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Trap destructor" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->energyPoints < this->hitPoints)
	{
		std::cout << "not enough points to attack" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " attack "\
		<< target << " causing " << this->hitPoints
		<< " points of damage"
		<< std::endl;
		this->energyPoints -= this->hitPoints;
	}
}

void ScavTrap::guardgate()
{
	std::cout << "gate keeper  mode" << std::endl;
}
