
#ifndef FORM_HPP
#define FORM_HPP

class Form 
{
	private:
		const std::string	name;
		bool				sign;
		const int			grade_sign;
		const int			grade_exec;
	public:
		Form(void);
		Form(const Form &src);
		Form operator = (const Form &src);
		~Form(void);
		const std::string	getName(void);
		bool				getSign(void);
		const int			getSignGrade(void);
		const int			getExecGrade(void);
		void				beSigned(class Bureaucrat);

};

std::ostream& operator << (std::ostream &out, Bureaucrat &src);

#endif
