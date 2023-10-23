/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:52 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:20:58 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"

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

typedef struct s_both
{
	t_stack	a;
	t_stack	b;
}	t_both;

//check_args.c
char	*ft_join_argv(int argc, char **argv);
int		ft_check_args(char *args, int *count);
int		ft_check_dup(t_stack *stack);

//stack_funcs.c
void	ft_stack_clear(t_stack *stack);
void	ft_stack_add(t_stack *stack, int num);
int		ft_stack_pop(t_stack *stack);
void	ft_stack_switch_all(t_stack *stack);

//stack_moves.c
void	ft_stack_swap(t_stack *stack, char *str);
void	ft_stack_rotate(t_stack *stack, char *str);
void	ft_stack_rev_rotate(t_stack *stack, char *msg);
void	ft_stack_push(t_stack *lhs, t_stack *rhs, char *msg);

//small_sort.c
void	ft_sort_random(t_stack *stack_a, t_stack *stack_b);
int		ft_is_sorted(t_stack *stack);

//large_sort.c
void	ft_sort_large(t_stack *stack_a, t_stack *stack_b);

//large_sort_utils.c
int		ft_get_max(t_stack *stack);
int		ft_get_mean(t_stack *stack);

#endif //!PUSH_SWAP_H