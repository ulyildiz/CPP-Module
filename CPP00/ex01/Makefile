NAME = phonebook
SRC = 	PhoneBook.cpp \
		Contact.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re