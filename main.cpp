
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat test(150);

	try {
		test.incrementGrade();
	}
	catch (...) {
		std::cout<<"error"<<std::endl;
	}
	std::cout<<test;
	return (0);
}
