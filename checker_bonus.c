/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:21:19 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/24 16:38:22 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_parse_to_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = ft_strlen(move);
	if (ft_strncmp(move, "sa", len) == 0)
		ft_stack_swap(stack_a, "sa\n");
	if (ft_strncmp(move, "sb", len) == 0 || ft_strncmp(move, "ss", len) == 0)
		ft_stack_swap(stack_b, "sb\n");
	if (ft_strncmp(move, "ss", len) == 0)
	{
		ft_stack_swap(stack_a, "sa\n");
		ft_stack_swap(stack_b, "sb\n");
	}
	if (ft_strncmp(move, "pb", len) == 0)
		ft_stack_push(stack_a, stack_b, "pb\n");
	if (ft_strncmp(move, "pa", len) == 0)
		ft_stack_push(stack_b, stack_a, "pa\n");
	if (ft_strncmp(move, "rra", len) == 0 || ft_strncmp(move, "rrr", len) == 0)
		ft_stack_rev_rotate(stack_a, "rra\n");
	if (ft_strncmp(move, "rrb", len) == 0 || ft_strncmp(move, "rrr", len) == 0)
		ft_stack_rev_rotate(stack_b, "rrb\n");
	if (ft_strncmp(move, "ra", len) == 0 || ft_strncmp(move, "rr", len) == 0)
		ft_stack_rotate(stack_a, "ra\n");
	if (ft_strncmp(move, "rb", len) == 0 || ft_strncmp(move, "rr", len) == 0)
		ft_stack_rotate(stack_b, "rb\n");
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
		return (ft_error(MALLOC_FAIL));
	if (ft_check_args(args, &count))
		return (ft_error(BAD_ARGS));
	if (ft_init_stacks(args, &stack_a, &stack_b, count))
		return (MALLOC_FAIL);
	ft_do_moves(&stack_a, &stack_b);
	ft_print_stack(&stack_a);
	if (ft_is_sorted(&stack_a) && stack_b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
