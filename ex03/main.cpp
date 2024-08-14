
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	AForm* rrf;
	Intern someRandomIntern;

	Bureaucrat b1("Sergiu", 150);
	try
	{
		rrf = someRandomIntern.makeForm("presidential xpardon", "Bender");
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	return (0);
}
