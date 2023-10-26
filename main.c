/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:33 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/26 19:24:31 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_sort(t_stack *idx_a, t_stack *stack_b)
{
	if (idx_a->size > 25)
		ft_sort_large(idx_a, stack_b);
	else
		ft_sort_smaller(idx_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	idx_a;
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
	if (ft_make_idx_stack(&stack_a, &stack_b, &idx_a))
		return (MALLOC_FAIL);
	ft_sort(&idx_a, &stack_b);
	free(stack_a.data);
	free(stack_b.data);
	free(idx_a.data);
	return (SUCCESS);
}
