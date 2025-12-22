CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp ScavTrap.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)

