NAME = push_swap
CHECKER = checker
LIBFT = printf/libftprintf.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra -g
GNL = GNL/gnl.a

GNL_SRCS =	GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c \

GNL_OBJS = $(GNL_SRCS:.c=.o)

BON_SRCS = 	checker_bonus.c initialize_stacks.c check_args.c\
			stack_funcs.c stack_moves.c\

BON_OBJS = $(BON_SRCS:.c=.o)

SRC = 	main.c stack_funcs.c stack_moves.c check_args.c \
		large_sort.c large_sort_utils.c small_sort.c \
		initialize_stacks.c idx_stack.c\

OBJS = $(SRC:.c=.o)

CLR_RMV		:= \033[0m	
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	(cd printf && make all)

$(GNL): $(GNL_OBJS)
	@ echo "$(YELLOW)Creating $(GNL) Library.$(CLR_RMV)"
	ar rcs $(GNL) $(GNL_OBJS)
	@ echo "$(GREEN)$(GNL) Library CREATED!$(CLR_RMV)"

$(CHECKER): $(LIBFT) $(GNL) $(BON_OBJS)
	$(COMPILER) $(FLAGS) $(BON_OBJS) $(LIBFT) $(GNL) -o $(CHECKER)

bonus: $(CHECKER)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	(cd printf && make clean)
	rm -f $(OBJS) $(GNL_OBJS) $(BON_OBJS)

fclean: clean
	(cd printf && make fclean)
	rm -f $(NAME) $(CHECKER) $(GNL)

re: fclean all

.PHONY: clean fclean re bonus