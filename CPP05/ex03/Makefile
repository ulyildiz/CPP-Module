NAME = intern
SRC =	Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		main.cpp \
		Intern.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -g -Werror -std=c++98

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all