
#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructor class
// ------------------------------------------------------------------------

Intern::Intern(void) 
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern Intern::operator = (const Intern &src)
{
	(void)src;
	return *this;
}

Intern::~Intern(void)
{
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) const 
{
	AForm *form;
	std::string form_type[3] = {A, B, C};
	int i;

	for (i = 0; i < 3; i++) {
		if (form_type[i] == name)
			break ;
	}

	switch(i) {
		case SHRUBBERY:
			form = new ShrubberyCreationForm(target);
			std::cout<<"Intern creates "<<*form;
			break;
		case ROBOTOMY:
			form = new RobotomyRequestForm(target);
			std::cout<<"Intern creates "<<*form;
			break;
		case PRESIDENTIAL:
			form = new PresidentialPardonForm(target);
			std::cout<<"Intern creates "<<*form;
			break;
		default:
			form = NULL;
			std::cout<<"Intern cannot create form because the name -";
			std::cout<<name<<"- was not found!"<<std::endl;
	}
	return (form);
}
