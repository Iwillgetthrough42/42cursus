#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		std::string name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
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
		std::string getName() const;
		int getGrade() const;
		void setGrade(int const grade);
		void inc();
		void dec();
		void signForm(Form &f);
		void executeForm(Form & form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other);


#endif