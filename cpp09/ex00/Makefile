CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = BitcoinExchange.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = btc
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
