NAME = push_swap
LIBFT = printf/libftprintf.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra -g

SRC = main.c stack_funcs.c stack_moves.c check_args.c large_sort.c small_sort.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	(cd printf && make all)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	(cd printf && make clean)
	rm -f $(OBJS)

fclean: clean
	(cd printf && make fclean)
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: clean fclean re