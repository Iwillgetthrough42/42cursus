#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

class Phonebook
{
	private:
		Contact contacts[8];
		int index;
	public:
		Phonebook();
		~Phonebook();
		void fillContact();
		void printInfo();
		void search();
};

#endif