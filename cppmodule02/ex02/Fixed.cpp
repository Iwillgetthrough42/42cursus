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

bool Fixed::operator>(Fixed const &other)
{
	return (this->val > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other)
{
	return (this->val < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other)
{
	return (this->val >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other)
{
	return (this->val <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other)
{
	return (this->val == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other)
{
	return (this->val != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)
{
	return (Fixed(this->val + other.getRawBits()));
}

Fixed Fixed::operator-(Fixed const &other)
{
	return (Fixed(this->val - other.getRawBits()));
}

Fixed Fixed::operator*(Fixed const &other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->val += 1;
	return *this;
}

Fixed Fixed::operator++(int num)
{
	(void)num;
	Fixed tmp(*this);
	this->val = this->val + 1;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->val -= 1;
	return *this;
}

Fixed Fixed::operator--(int num)
{
	(void) num;
	Fixed tmp(*this);
	this->val -= 1;
	return (tmp);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if ((Fixed)num1 < (Fixed)num2)
		return (num1);
	return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if ((Fixed)num1 > (Fixed)num2)
		return (num1);
	return (num2);
}