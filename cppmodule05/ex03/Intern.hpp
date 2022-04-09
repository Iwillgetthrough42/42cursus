#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &other);
		Form *makeForm(std::string name, std::string target);
		Intern &operator=(Intern const &other);
};


#endif