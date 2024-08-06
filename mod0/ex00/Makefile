NAME=bdb.exec
SRC=$(wildcard source/*.cpp)
OBJ=$(patsubst source/%.cpp, object/%.o, $(SRC))
FLAGS=-std=c++98 -Wall -Wextra -Werror

all: $(NAME)
.PHONY: all

$(NAME): object $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

object/%.o: source/%.cpp
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
