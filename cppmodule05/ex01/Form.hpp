#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string const name;
		bool isSigned;
		int const signRequired;
		int const execRequired;
	public:
		Form();
		~Form();
		Form(std::string name, int const signRequired, int const execRequired);
		Form(Form const &other);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Form &operator=(Form const &other);
		std::string const  getName() const;
		bool getIsSigned() const;
		int const getSignRequired() const;
		int const getExecRequired() const;
		void beSigned(Bureaucrat &b);		
};

std::ostream &operator<<(std::ostream &o, Form const &other);

#endif