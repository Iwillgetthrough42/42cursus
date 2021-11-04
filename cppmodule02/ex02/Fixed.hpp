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
		bool operator>(Fixed const &other);
		bool operator<(Fixed const &other);
		bool operator>=(Fixed const &other);
		bool operator<=(Fixed const &other);
		Fixed &operator=(Fixed const &other);
		bool operator==(Fixed const &other);
		bool operator!=(Fixed const &other);
		Fixed operator+(Fixed const &other);
		Fixed operator-(Fixed const &other);
		Fixed operator*(Fixed const &other);
		Fixed operator/(Fixed const &other);
		Fixed &operator++();
		Fixed operator++(int num);
		Fixed &operator--();
		Fixed operator--(int num);
		static Fixed &min(Fixed &num1, Fixed  &num2);
		static const Fixed &min(const Fixed &num1, const Fixed &num2);
		static Fixed &max(Fixed &num1, Fixed &num2);
		static const Fixed &max(const Fixed &num1, const Fixed &num2);
};

std::ostream &operator<<(std::ostream & o, Fixed const &other);

#endif