NAME = IRC

HEADER = serv.hpp

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)

OBJ = $(patsubst %.cpp,%.o,$(SRC))

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re