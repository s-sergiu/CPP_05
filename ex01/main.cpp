
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat b1("Sergiu", 121);
	Form form1("Document", 120, 120);

	try	{
		form1.beSigned(b1);
	}
	catch (std::exception &e) {
		std::cout<<"Error:"<<e.what()<<std::endl;
	}

	b1.signForm(form1);
	std::cout<<b1;

	return (0);
}
