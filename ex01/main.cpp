
#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat b3;
	Bureaucrat b1("Sergiu", 3);
	Bureaucrat b5("Sergiu2");

	try	{
		b5.decrementGrade();
		b5.decrementGrade();
		b1.incrementGrade();
		b1.incrementGrade();
		b1.incrementGrade();
		Bureaucrat b2("Azer", 0);
	}
	catch (std::exception &e) {
		std::cout<<"Error: "<<e.what()<<std::endl;
	}

	std::cout<<b3;
	std::cout<<b1;
	std::cout<<b5;

	return (0);
}
