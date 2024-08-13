
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat b1("Sergiu", 20);
	Form form1("Document", 20, 130);

	b1.signForm(form1);
	std::cout<<b1;
	std::cout<<form1;

	return (0);
}
