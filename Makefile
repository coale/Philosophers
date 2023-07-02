NAME = philo

SRC = death.c forks.c init.c main.c philo_actions.c threads.c utils.c check_args.c

OBJ_S = $(SRC:.c=.o)

FLAG = -lpthread -Wall -Wextra -Werror

$(NAME): $(OBJ_S)
	@cc $(FLAG) $(SRC) -o $(NAME)

all: $(NAME)

re: fclean all

clean: 
	rm -f ${OBJ_S}

fclean: clean
	rm -rf $(NAME)
	
.PHONY: all re clean fclean
