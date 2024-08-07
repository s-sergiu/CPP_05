
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat b1("Sergiu", 21);
	Form form1("Document", 20, 130);

	try	{
		form1.beSigned(b1);
	}
	catch (std::exception &e) {
		std::cout<<"\e[31m\e[7mError:"<<e.what()<<std::endl;
	}

	b1.signForm(form1);
	std::cout<<b1;
	std::cout<<form1;

	return (0);
}
