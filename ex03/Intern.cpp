
#include "Intern.hpp"

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

void Intern::makeForm(const std::string &name, const std::string &target) const 
{
	std::cout<<"name: "<<name<<std::endl;
	std::cout<<"target: "<<target<<std::endl;
}
