FLAGS=-Wall -Wextra -Werror -std=c++98 -I.
NAME=DivideAndRule

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: $(NAME)
.PHONY: all

$(NAME): $(OBJECTS)
	@c++ $(FLAGS) -o $(NAME) $(OBJECTS)

debug: fclean
	@c++ $(FLAGS) -g3 -o $(NAME) $(SOURCES)
.PHONY: debug

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJECTS)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
