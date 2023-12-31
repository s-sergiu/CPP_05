
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyForm", 145, 137)
{
	this->target = target;
	this->isSigned = false;
	std::cout<<"AForm <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShrubberyForm", 145, 137)
{
	this->target = src.getTarget();
	this->isSigned = src.getSign();
}

ShrubberyCreationForm ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src)
{
	this->target = src.getTarget();
	this->isSigned = src.getSign();	
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout<<"AForm <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	
	std::ofstream out(this->getTarget().append("_shrubbery"));

	out<<executor.getName();
	out<<"	                                               ."<<std::endl;
	out<<"					     .        ;"<<std::endl;
	out<<"		.              .              ;%     ;;"<<std::endl;
	out<<"                  ,           ,                :;%  %;"<<std::endl;
	out<<"                   :         ;                   :;%;'     .,"<<std::endl;
	out<<"          ,.        %;     %;            ;        %;'    ,;"<<std::endl;
	out<<"            ;       ;%;  %%;        ,     %;    ;%;    ,%'"<<std::endl;
	out<<"             %;       %;%;      ,  ;       %;  ;%;   ,%;'"<<std::endl;
	out<<"              ;%;      %;        ;%;        % ;%;  ,%;'"<<std::endl;
	out<<"               `%;.     ;%;     %;'         `;%%;.%;'"<<std::endl;
	out<<"                `:;%.    ;%%. %@;        %; ;@%;%'"<<std::endl;
	out<<"                   `:%;.  :;bd%;          %;@%;'"<<std::endl;
	out<<"                     `@%:.  :;%.         ;@@%;'"<<std::endl;
	out<<"                       `@%.  `;@%.      ;@@%;"<<std::endl;
	out<<"                         `@%%. `@%%    ;@@%;"<<std::endl;
	out<<"                           ;@%. :@%%  %@@%;"<<std::endl;
	out<<"                             %@bd%%%bd%%:;"<<std::endl;
	out<<"                               #@%%%%%:;;"<<std::endl;
	out<<"                               %@@%%%::;"<<std::endl;
	out<<"                               %@@@%(o);  . '"<<std::endl;
	out<<"                               %@@@o%;:(.,'"<<std::endl;
	out<<"                           `.. %@@@o%::;"<<std::endl;
	out<<"                              `)@@@o%::;"<<std::endl;
	out<<"                               %@@(o)::;"<<std::endl;
	out<<"                              .%@@@@%::;"<<std::endl;
	out<<"                              ;%@@@@%::;."<<std::endl;
	out<<"                             ;%@@@@%%:;;;."<<std::endl;
	out<<"                         ...;%@@@@@%%:;;;;,.."<<std::endl;
	out.close();
}
