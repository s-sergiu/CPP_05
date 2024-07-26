
#include "Bureaucrat.hpp"
#include <cstdlib>

void	chcklks(void)	{
	system ("leaks main");
}

int main(void)
{
	try
	{
		Bureaucrat	Sergiu("Sergiu");
		Bureaucrat	Unnamed;
		Bureaucrat	Jim("Jim", 150);
		Bureaucrat	*Jon = new Bureaucrat("Jon", 1);
		Bureaucrat	Ben(*Jon);
		Bureaucrat	*Bob = new Bureaucrat("Bobby", 50);

		std::cout << std::endl;
		std::cout << *Bob;
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
		// creating empty pointer to save Bob's address and free it at the end;
		Bureaucrat *empty_ptr = Bob;
		Bob = Jon;

		std::cout <<*Bob << std::endl;

		delete empty_ptr;
		delete Jon;
	}
	catch(std::exception &e)
	{
		std::cout<<"\e[41mERROR:\e[0m "<<e.what()<<std::endl;	
	}
	atexit(chcklks);
	return (0);
}
