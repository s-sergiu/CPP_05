
#include "Bureaucrat.hpp"
#include <cstdlib>

void	chcklks(void)	{
	system ("leaks main");
}

int main(void)
{
	try
	{
		Bureaucrat	*Bob = new Bureaucrat("test", 2);
		Bureaucrat	Sergiu("Sergiu");
		Bureaucrat	*Jon = new Bureaucrat("Jon", 1);
		Bureaucrat	Jim("Jim", 150);
		Bureaucrat	Ben(*Jon);

		std::cout << std::endl;
		std::cout << Bob;
		std::cout << Sergiu;
		std::cout << *Jon;
		std::cout << Jim;
		std::cout << Ben;
		std::cout << std::endl;

		try {
			Ben.incrementGrade();		
		} catch (std::exception &e) {
			std::cout<<"\e[41mERROR:\e[0m "<<e.what()<<std::endl;	
		}

		try {
			Jim.decrementGrade();		
		} catch (std::exception &e) {
			std::cout<<"\e[41mERROR:\e[0m "<<e.what()<<std::endl;	
		}

		Bob = Jon;

		std::cout <<*Bob << std::endl;

		delete Jon;
	}
	catch(std::exception &e)
	{
		std::cout<<"\e[41mERROR:\e[0m "<<e.what()<<std::endl;	
	}
	return (0);
}
