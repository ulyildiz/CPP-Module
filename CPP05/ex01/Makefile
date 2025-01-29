NAME = Form
SRC =	Bureaucrat.cpp \
		Form.cpp \
		main.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -g -std=c++98

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