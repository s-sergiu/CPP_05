
#include "ShrubberyCreationForm.hpp"

// Constructor class
// ------------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyForm", 145, 137)
{
	this->target = target;
	this->isSigned = false;
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
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

// Class functions 
// ------------------------------------------------------------------------

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	
	if (executor.getGrade() <= this->getExecGrade()) {
		std::ofstream out(this->getTarget().append("_shrubbery").c_str());
		out<<"	                                               ."<<std::endl;
		out<<"					     .        ;"<<std::endl;
		out<<"		.              .              ;%     ;;"<<std::endl;
		out<<"                  ,           ,                :;%  %;"<<std::endl;
		out<<"                   :         ;                   :;%;'     .,";
		out<<std::endl;
		out<<"          ,.        %;     %;            ;        %;'    ,;";
		out<<std::endl;
		out<<"            ;       ;%;  %%;        ,     %;    ;%;    ,%'";
		out<<std::endl;
		out<<"             %;       %;%;      ,  ;       %;  ;%;   ,%;'";
		out<<std::endl;
		out<<"              ;%;      %;        ;%;        % ;%;  ,%;'";
		out<<std::endl;
		out<<"               `%;.     ;%;     %;'         `;%%;.%;'";
		out<<std::endl;
		out<<"                `:;%.    ;%%. %@;        %; ;@%;%'";
		out<<std::endl;
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
	} else {
		throw AForm::GradeTooLowException(this->getName(), ": Executing!");
	}
}
