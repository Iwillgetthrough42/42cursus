#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
class Form;
#include <string>

class RobotomyRequestForm : public Form
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm &other);
		void virtual action();
		std::string getTarget() const;
		void setTarget(std::string const target);
};



#endif