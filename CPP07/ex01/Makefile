NAME = iter
SOURCE = main.cpp 
OBJ = $(SOURCE:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re