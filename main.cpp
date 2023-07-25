
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat test(150);
	std::string word = "test";


	try	{
		//std::cout<< word.at(4) << std::endl;
		test.decrementGrade();
		//test.incrementGrade();
	}
	catch (myException &e) {
		std::cout<<"error "<<e.what()<<std::endl;
	}
	std::cout<<test;
	return (0);
}
