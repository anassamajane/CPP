CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp Form.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = Form

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
