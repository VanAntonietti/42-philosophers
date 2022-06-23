NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror

FILES	=	main.c			\
			init_struct.c

SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):
	$(CC) -I . $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:fclean all