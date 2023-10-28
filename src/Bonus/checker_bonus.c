/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:21:19 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/28 15:39:14 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_check_double(char *move, t_stack *stack_a, t_stack *stack_b,
	int len)
{
	if (!ft_strncmp(move, "ss\n", len))
	{
		ft_stack_swap(stack_a, "");
		ft_stack_swap(stack_b, "");
	}
	else if (!ft_strncmp(move, "rrr\n", len))
	{
		ft_stack_rev_rotate(stack_a, "");
		ft_stack_rev_rotate(stack_b, "");
	}
	else if (!ft_strncmp(move, "rr\n", len))
	{
		ft_stack_rotate(stack_a, "");
		ft_stack_rotate(stack_b, "");
	}
	else
		return (1);
	return (SUCCESS);
}

static int	ft_parse_to_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = ft_strlen(move) + 1;
	if (!ft_strncmp(move, "rra\n", len))
		ft_stack_rev_rotate(stack_a, "");
	else if (!ft_strncmp(move, "rrb\n", len))
		ft_stack_rev_rotate(stack_b, "");
	else if (!ft_check_double(move, stack_a, stack_b, len))
		return (SUCCESS);
	else if (!ft_strncmp(move, "sa\n", len))
		ft_stack_swap(stack_a, "");
	else if (!ft_strncmp(move, "sb\n", len))
		ft_stack_swap(stack_b, "");
	else if (!ft_strncmp(move, "pb\n", len))
		ft_stack_push(stack_a, stack_b, "");
	else if (!ft_strncmp(move, "pa\n", len))
		ft_stack_push(stack_b, stack_a, "");
	else if (!ft_strncmp(move, "ra\n", len))
		ft_stack_rotate(stack_a, "");
	else if (!ft_strncmp(move, "rb\n", len))
		ft_stack_rotate(stack_b, "");
	else
		return (1);
	return (SUCCESS);
}

int	ft_do_moves(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		err;

	err = SUCCESS;
	line = (char *)2;
	while (line != NULL && err == 0)
	{
		line = get_next_line(0);
		if (line != NULL)
			err = ft_parse_to_move(line, stack_a, stack_b);
		free(line);
	}
	return (err);
}

static int	ft_destroy(int err, t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->data);
	free(stack_b->data);
	return (err);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*args;
	int		count;

	count = 0;
	if (argc < 2)
		return (0);
	args = ft_join_argv(argc, argv);
	if (args == NULL)
		return (ft_error(MALLOC_FAIL, NULL));
	if (ft_check_args(args, &count))
		return (ft_error(BAD_ARGS, args));
	if (ft_init_stacks(args, &stack_a, &stack_b, count))
		return (MALLOC_FAIL);
	if (ft_do_moves(&stack_a, &stack_b))
		return (ft_destroy(ft_error(1, NULL), &stack_a, &stack_b));
	if (stack_b.size == 0 && ft_is_sorted(&stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (ft_destroy(0, &stack_a, &stack_b));
}
