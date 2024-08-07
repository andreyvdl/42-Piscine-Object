NAME=bdb.exec
SRC=$(wildcard source/*.cpp)
OBJ=$(patsubst source/%.cpp, object/%.o, $(SRC))
FLAGS=-std=c++98 -Wall -Wextra -Werror -I./include
INCLUDES=$(wildcard include/*.hpp)

all: $(NAME)
.PHONY: all

$(NAME): object $(OBJ) $(INCLUDES)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

object/%.o: source/%.cpp $(INCLUDES)
	c++ $(FLAGS) -c $< -o $@

object:
	mkdir -p object

clean:
	rm -fr object
.PHONY: clean

fclean: clean
	rm -fr $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
