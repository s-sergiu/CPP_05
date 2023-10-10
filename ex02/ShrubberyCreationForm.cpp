#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyForm", 145, 137)
{
	(void)target;
	this->isSigned = false;
	std::cout<<"AForm <"<<name;
	std::cout<<"> initialized successfully!"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShrubberyForm", 145, 137)
{
	this->isSigned = src.getSign();
}

ShrubberyCreationForm ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src)
{
	this->isSigned = src.getSign();	
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout<<"AForm <"<<name;
	std::cout<<"> destroyed successfully!"<<std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout<<executor.getName();
	std::cout<<"	                                               ."<<std::endl;
	std::cout<<"					     .        ;"<<std::endl;
	std::cout<<"		.              .              ;%     ;;"<<std::endl;
	std::cout<<"                  ,           ,                :;%  %;"<<std::endl;
	std::cout<<"                   :         ;                   :;%;'     .,"<<std::endl;
	std::cout<<"          ,.        %;     %;            ;        %;'    ,;"<<std::endl;
	std::cout<<"            ;       ;%;  %%;        ,     %;    ;%;    ,%'"<<std::endl;
	std::cout<<"             %;       %;%;      ,  ;       %;  ;%;   ,%;'"<<std::endl;
	std::cout<<"              ;%;      %;        ;%;        % ;%;  ,%;'"<<std::endl;
	std::cout<<"               `%;.     ;%;     %;'         `;%%;.%;'"<<std::endl;
	std::cout<<"                `:;%.    ;%%. %@;        %; ;@%;%'"<<std::endl;
	std::cout<<"                   `:%;.  :;bd%;          %;@%;'"<<std::endl;
	std::cout<<"                     `@%:.  :;%.         ;@@%;'"<<std::endl;
	std::cout<<"                       `@%.  `;@%.      ;@@%;"<<std::endl;
	std::cout<<"                         `@%%. `@%%    ;@@%;"<<std::endl;
	std::cout<<"                           ;@%. :@%%  %@@%;"<<std::endl;
	std::cout<<"                             %@bd%%%bd%%:;"<<std::endl;
	std::cout<<"                               #@%%%%%:;;"<<std::endl;
	std::cout<<"                               %@@%%%::;"<<std::endl;
	std::cout<<"                               %@@@%(o);  . '"<<std::endl;
	std::cout<<"                               %@@@o%;:(.,'"<<std::endl;
	std::cout<<"                           `.. %@@@o%::;"<<std::endl;
	std::cout<<"                              `)@@@o%::;"<<std::endl;
	std::cout<<"                               %@@(o)::;"<<std::endl;
	std::cout<<"                              .%@@@@%::;"<<std::endl;
	std::cout<<"                              ;%@@@@%::;."<<std::endl;
	std::cout<<"                             ;%@@@@%%:;;;."<<std::endl;
	std::cout<<"                         ...;%@@@@@%%:;;;;,.."<<std::endl;
}
