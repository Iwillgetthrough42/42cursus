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
		Zombie(std::string type, std::string name);
		Zombie();
		std::string getName() const;
		std::string getType() const;
		void setName(std::string name);
		void setType(std::string type);

};

#endif