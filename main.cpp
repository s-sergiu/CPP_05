
#include "Bureaucrat.hpp"

int main(void)
{

	try	{
		Bureaucrat b1("Sergiu", 150);
		Bureaucrat b2("Azer", 0);
		//b1.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout<<"Message: "<<e.what()<<std::endl;
	}
	//std::cout<<b1;
	//std::cout<<b2;
	return (0);
}
