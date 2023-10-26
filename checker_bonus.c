/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:21:19 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/26 19:39:26 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_to_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = ft_strlen(move);
	if (ft_strncmp(move, "sa\n", len) == 0)
		ft_stack_swap(stack_a, "");
	if (ft_strncmp(move, "sb\n", len) == 0)
		ft_stack_swap(stack_b, "");
	if (ft_strncmp(move, "ss\n", len) == 0)
	{
		ft_stack_swap(stack_a, "");
		ft_stack_swap(stack_b, "");
	}
	if (ft_strncmp(move, "pb\n", len) == 0)
		ft_stack_push(stack_a, stack_b, "");
	if (ft_strncmp(move, "pa\n", len) == 0)
		ft_stack_push(stack_b, stack_a, "");
	if (ft_strncmp(move, "rra\n", len) == 0
		|| ft_strncmp(move, "rrr\n", len) == 0)
		ft_stack_rev_rotate(stack_a, "");
	if (ft_strncmp(move, "rrb\n", len) == 0
		|| ft_strncmp(move, "rrr\n", len) == 0)
		ft_stack_rev_rotate(stack_b, "");
	if (ft_strncmp(move, "ra\n", len) == 0
		|| ft_strncmp(move, "rr\n", len) == 0)
		ft_stack_rotate(stack_a, "");
	if (ft_strncmp(move, "rb\n", len) == 0
		|| ft_strncmp(move, "rr\n", len) == 0)
		ft_stack_rotate(stack_b, "");
}

int	ft_do_moves(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = (char *)2;
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line != NULL)
			ft_parse_to_move(line, stack_a, stack_b);
		free(line);
	}
	return (SUCCESS);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = stack->size;
	while (i--)
		ft_printf("%i\n", stack->data[i]);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*args;
	int		count;

	count = 0;
	if (argc < 2)
		return (1);
	args = ft_join_argv(argc, argv);
	if (args == NULL)
		return (ft_error(MALLOC_FAIL, NULL));
	if (ft_check_args(args, &count))
		return (ft_error(BAD_ARGS, args));
	if (ft_init_stacks(args, &stack_a, &stack_b, count))
		return (MALLOC_FAIL);
	ft_do_moves(&stack_a, &stack_b);
	//ft_print_stack(&stack_a);
	if (stack_b.size == 0 && ft_is_sorted(&stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
