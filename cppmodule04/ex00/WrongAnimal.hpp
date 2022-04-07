#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &other);
		WrongAnimal(WrongAnimal const &other);
		void makeSound() const;
		std::string getType() const;
};

#endif