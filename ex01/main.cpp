
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat b1("Sergiu", 10);
	Form form1("Document", 100, 130);

	try	{
		form1.beSigned(b1);
	}
	catch (std::exception &e) {
		std::cout<<"\e[31mError:"<<e.what()<<std::endl;
	}

	b1.signForm(form1);
	std::cout<<b1;
	std::cout<<form1;

	return (0);
}
