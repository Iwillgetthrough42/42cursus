#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():name(" "), isSigned(false), signRequired(150), execRequired(150)
{

}

Form::~Form()
{

}

Form::Form(std::string name, \
int const signRequired, int const execRequired) : name(name),isSigned(false),\
signRequired(signRequired), execRequired(execRequired)
{
	if (this->signRequired > 150 || this->execRequired > 150)
		throw GradeTooLowException();
	else if (this->signRequired <= 0 || this->execRequired <= 0)
		throw GradeTooHighException();
}

Form::Form(Form const &other): name(other.getName()), isSigned(other.getIsSigned()), \
signRequired(other.getSignRequired()), execRequired(other.getExecRequired())
{

}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::string const Form::getName() const
{
	return (this->name);
}

Form &Form::operator=(Form const &other)
{
	this->isSigned = other.isSigned;
	return (*this);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int const Form::getSignRequired() const
{
	return (this->signRequired);
}

int const Form::getExecRequired() const
{
	return (this->execRequired);
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->signRequired)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &o, Form const &other)
{
	o << " Form " << other.getName() << 
	" required grade to sign " << other.getSignRequired() << \
	" required grade to exec " << other.getExecRequired();
	return (o);
}