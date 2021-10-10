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
			std::string login;
			std::string postal;
			std::string email;
			std::string phoneNum;
			std::string birthday;
			std::string meal;
			std::string underwCol;
			std::string secret;
		};
		struct vars fields;
};

#endif