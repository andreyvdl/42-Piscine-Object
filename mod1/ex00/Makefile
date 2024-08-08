NAME=worker.exec
SRC=$(wildcard source/*.cpp)
OBJ=$(patsubst source/%.cpp, object/%.o, $(SRC))
INCLUDE=$(wildcard include/*.hpp)
FLAGS=-std=c++98 -Wall -Wextra -Werror -I./include

all: $(NAME)
.PHONY: all

$(NAME): object $(OBJ) $(INCLUDE)
	c++ $(FLAGS) $(OBJ) -o $@

object:
	mkdir -p object

object/%.o: source/%.cpp $(INCLUDE)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -fr object
.PHONY: clean

fclean: clean
	rm -fr $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
