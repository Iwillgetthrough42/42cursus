#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat &operator=(const Cat &other);
		Cat(Cat const &other);
		void virtual makeSound() const;

};

#endif