
#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat b3;
	Bureaucrat b1("Sergiu", 150);

	try	{
		Bureaucrat b2("Azer", 0);
		//b1.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout<<"Error: "<<e.what()<<std::endl;
	}
	std::cout<<b3;
	std::cout<<b1;
	return (0);
}
