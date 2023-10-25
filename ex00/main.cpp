
#include "Bureaucrat.hpp"
#include <cstdlib>

void	chcklks(void)	{
	//system ("leaks main");
}

int main(void)
{
	try
	{
		Bureaucrat	Bob;
		Bureaucrat	Sergiu("Sergiu");
		Bureaucrat	*Jon = new Bureaucrat("Jon", 1);
		Bureaucrat	Jim("Jim", 100);
		Bureaucrat	Ben(*Jon);

		std::cout << Bob << std::endl;
		std::cout << Sergiu << std::endl;
		std::cout << *Jon << std::endl;
		std::cout << Jim  << std::endl;
		std::cout << Ben << std::endl;

		Bob = Jim;

		std::cout << Bob << std::endl;

		delete Jon;
	}
	catch(std::exception & e)
	{
		std::cout<<"\e[41mERROR:\e[0m "<<e.what()<<std::endl;	
	}
	return (0);
}
