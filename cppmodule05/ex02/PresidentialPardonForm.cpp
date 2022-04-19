#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("")
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  \
Form("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : Form(other), target(other.getTarget())
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	this->target = other.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::action()
{
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox " << std::endl;
}

void PresidentialPardonForm::setTarget(std::string const target)
{
	this->target = target;
}












