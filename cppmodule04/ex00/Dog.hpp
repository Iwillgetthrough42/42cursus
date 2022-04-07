#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog &operator=(const Dog &other);
		Dog(Dog const &other);
		void virtual makeSound() const;
};

#endif