#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void Add();
		void print();
		std::string printable(std:: string);
		void search(int i);
	private:
		static std::string fields[11];
		std::string vars[11][8];
		int index;
};

#endif