#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int val;
		static const int frac = 8;
	public:
		Fixed();
		Fixed(const int original);
		Fixed(const float original);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed(Fixed const &other);
		int getRawBits() const;
		void setRawBits(int const raw);
		Fixed &operator=(Fixed const &other);
};

std::ostream &operator<<(std::ostream & o, Fixed const &other);

#endif