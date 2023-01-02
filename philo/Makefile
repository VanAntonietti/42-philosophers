NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror

FILES	=	main.c \
			init.c \
			utils.c \
			philo.c

SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):
	$(CC) -I /src $(FLAGS) $(SRC) -g3 -pthread -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:fclean all

.PHONY: all clean fclean re