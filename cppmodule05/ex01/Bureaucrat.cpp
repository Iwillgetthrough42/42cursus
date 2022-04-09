#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat():name(""), grade(150)
{

}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::inc()
{
	if (this->grade - 1 <= 0)
		throw GradeTooHighException();
	--this->grade;
}

void Bureaucrat::dec()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	++this->grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this == &other)
		return (*this);
	this->grade = other.getGrade();
	this->name = other.getName();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low");
}

void Bureaucrat::setGrade(int const grade)
{
	if (grade <= 0)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	this->grade = grade;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << " Bureaucrat " << this->name << " signs " \
		<< f.getName() << " form " << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << " Bureaucrat " << this->name << " can't sign " \
		<< f.getName() << " form  because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << " Bureaucrat Grade " << other.getGrade();
	return (o);
}
