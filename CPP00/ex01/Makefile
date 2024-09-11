NAME = phonebook
SRC = 	phoneBook.cpp \
		contact.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)
CFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re