NAME = push_swap
CHECKER = checker
LIBFT = printf/libftprintf.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra
GNL = GNL/gnl.a
SRC = ./src
BONUS = $(SRC)/Bonus

GNL_SRCS =	GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c \

GNL_OBJS = $(GNL_SRCS:.c=.o)

BON_SRCS = 	$(BONUS)/checker_bonus.c $(BONUS)/initialize_stacks_bonus.c \
			$(BONUS)/check_args_bonus.c $(BONUS)/stack_funcs_bonus.c \
			$(BONUS)/stack_moves_bonus.c\

BON_OBJS = $(BON_SRCS:.c=.o)

MAN_SRC = 	$(SRC)/main.c $(SRC)/stack_funcs.c $(SRC)/stack_moves.c $(SRC)/check_args.c \
			$(SRC)/large_sort.c $(SRC)/large_sort_utils.c $(SRC)/small_sort.c \
			$(SRC)/initialize_stacks.c $(SRC)/idx_stack.c\

MAN_OBJS = $(MAN_SRC:.c=.o)

CLR_RMV		:= \033[0m	
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

all: $(NAME)

$(NAME): $(LIBFT) $(MAN_OBJS)
	$(COMPILER) $(FLAGS) $(MAN_OBJS) $(LIBFT) -o $(NAME)

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
	rm -f $(MAN_OBJS) $(GNL_OBJS) $(BON_OBJS)

fclean: clean
	(cd printf && make fclean)
	rm -f $(NAME) $(CHECKER) $(GNL)

re: fclean all

.PHONY: clean fclean re bonus all
