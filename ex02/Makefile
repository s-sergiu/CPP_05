NAME = main
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = main.cpp \
	  Bureaucrat.cpp \
	  AForm.cpp \
	  ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp \
	  PresidentialPardonForm.cpp

OBJ = main.o \
	  Bureaucrat.o \
	  AForm.o \
	  ShrubberyCreationForm.o \
	  RobotomyRequestForm.o \
	  PresidentialPardonForm.o

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all

.PHONY:all clean fclean re
