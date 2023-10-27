/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:52 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/27 17:09:08 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../printf/ft_printf.h"
# include "../../GNL/get_next_line_bonus.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_error
{
	SUCCESS,
	MALLOC_FAIL,
	NO_ARGS,
	BAD_ARGS,
	INT_OVERFLOW,
	HAS_DUPLICATE
}	t_error;

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

//check_args.c
char	*ft_join_argv(int argc, char **argv);
int		ft_check_args(char *args, int *count);
int		ft_check_dup(t_stack *stack);

//initialize_stacks.c
int		ft_error(int errnum, char *freeit);
int		ft_fill_stack(char *args, t_stack *stack, int size);
int		ft_allocate_stacks(t_stack *stack_a, t_stack *stack_b, int size);
int		ft_init_stacks(
			char *args, t_stack *stack_a, t_stack *stack_b, int size);

//stack_funcs.c
void	ft_stack_clear(t_stack *stack);
void	ft_stack_add(t_stack *stack, int num);
int		ft_stack_pop(t_stack *stack);
void	ft_stack_switch_all(t_stack *stack);
int		ft_is_sorted(t_stack *stack);

//stack_moves.c
void	ft_stack_swap(t_stack *stack, char *str);
void	ft_stack_rotate(t_stack *stack, char *str);
void	ft_stack_rev_rotate(t_stack *stack, char *msg);
void	ft_stack_push(t_stack *lhs, t_stack *rhs, char *msg);

#endif //!PUSH_SWAP_BONUS_H