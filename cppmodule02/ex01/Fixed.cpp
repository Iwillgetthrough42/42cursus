#include "Fixed.hpp"

Fixed::Fixed()
{
	this->val = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructot called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int original)
{
	this->val = original << this->frac;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float original)
{
	this->val = roundf(original * (1 << this->frac));
	std::cout << "float constructor called" << std::endl;
}

Fixed &Fixed::operator=( Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->val = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	return (this->val);
}

void Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

float Fixed::toFloat( ) const
{
	return ((float)this->val / (float) (1 << this->frac));
}

int Fixed::toInt( void ) const
{
	return (this->val >> this->frac);
}

std::ostream &operator<<(std::ostream & o, Fixed const &other)
{
	o << other.toFloat();
	return (o);
}

