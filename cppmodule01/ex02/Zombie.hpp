#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string type;
		std::string name;
	public:
		void announce();
		Zombie();
		Zombie(std::string type, std::string name);
		std::string getName() const;
		std::string getType() const;
		void setName(std::string name);
		void setType(std::string type);

};

#endif