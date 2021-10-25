#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void Add();
		std::string printable(std::string str);
		void print();
		void printAll();
		
	private:
		struct vars
		{
			std::string name;
			std::string lastName;
			std::string nickName;
			std::string phoneNum;
			std::string secret;
		};
		struct vars fields;
};

#endif