
#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat b1("Sergiu", 150);

	try	{
		b1.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	std::cout<<b1;

	return (0);
}
