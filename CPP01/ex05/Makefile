NAME = harl
SRC =	main.cpp \
		Harl.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

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