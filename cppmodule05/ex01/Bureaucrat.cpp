#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
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
	--this->grade;
	if (this->grade <= 0)
		throw GradeTooHighException();
}

void Bureaucrat::dec()
{
	++this->grade;
	if (this->grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this == &other)
		return (*this);
	this->grade = other.getGrade();
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
	this->grade = grade;
	if (this->grade <= 0)
		throw GradeTooLowException();
	else if (this->grade > 150)
		throw GradeTooHighException();
}


std::ostream &operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << " Bureaucrat Grade " << other.getGrade();
	return (o);
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
