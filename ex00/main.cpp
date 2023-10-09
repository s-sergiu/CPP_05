
#include "Bureaucrat.hpp"

void	chcklks(void)	{
	system ("leaks main");
}

int main(void)
{
	atexit(chcklks);
	{
		std::cout << "	#############" << std::endl;
		std::cout << "	# CanonTEST #" << std::endl;
		std::cout << "	#############" << std::endl;

		Bureaucrat	Bob;
		Bureaucrat	*Jon = new Bureaucrat("Jon", 1);
		Bureaucrat	Jim("Jim", 111);
		Bureaucrat	Ben(*Jon);

		std::cout << Bob << std::endl;
		std::cout << *Jon << std::endl;
		std::cout << Jim  << std::endl;
		std::cout << Ben << std::endl;

		Bob = Jim;

		std::cout << Bob << std::endl;

		delete Jon;
	}
	return (0);
}
