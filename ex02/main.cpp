
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("Sergiu", 140);
	try
	{
		ShrubberyCreationForm object("Home");
		object.execute(b1);
		std::cout<<"SignGrade: "<<object.getSignGrade()<<std::endl;
		std::cout<<"ExecGrade: "<<object.getExecGrade()<<std::endl;
		object.beSigned(b1);
		object.getSigner();
	}
	catch (std::exception &e)
	{
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}
	return (0);
}
