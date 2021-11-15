#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target(target), Form("PresidentialPardonForm", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target), \
Form("PresidentialPardonForm", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : target(other.getTarget())
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












