#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int val;
		static const int frac = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		int getRawBits() const;
		void setRawBits(int const raw);
		Fixed &operator=(Fixed const &other);
};

#endif