#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor" << std::endl; 
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	if (this == &other)
		return (*this);
	this->name = other.getName();
	this->hitPoints = other.getHitPoints();
	this->energyPoints = other.getEnergyPoints();
	this->attackDamage = other.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints < this->hitPoints)
	{
		std::cout << "not enough points to attack" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attack "\
		<< target << " causing " << this->hitPoints
		<< " points of damage"
		<< std::endl;
		this->energyPoints -= this->hitPoints;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
	}
	else
		this->hitPoints -= amount;
	this->attackDamage = amount;
	std::cout << "ClapTrap " << this ->name << " lost " << amount <<\
	" points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints + amount <= 10)
		this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repaired " \
	<< amount << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);      
}

int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void ClapTrap::setHitPoints(unsigned int points)
{
	this->hitPoints = points;
}

void ClapTrap::setEnergyPoints(unsigned int points)
{
	this->energyPoints = points;
}

void ClapTrap::setAttackDamage(unsigned int damage)
{
	this->attackDamage = damage;
}
