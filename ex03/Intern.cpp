
#include "Intern.hpp"

// Constructor class
// ------------------------------------------------------------------------

Intern::Intern(void) 
{
}

Intern::Intern(const Intern &src)
{
	this->grade = src.getGrade();
}

Intern Intern::operator = (const Intern &src)
{
	this->grade = src.getGrade();
	return *this;
}

Intern::~Intern(void)
{
}
