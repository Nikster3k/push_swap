/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:33 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/24 14:58:24 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack_a.size > 25)
		ft_sort_large(&stack_a, &stack_b);
	else
		ft_sort_random(&stack_a, &stack_b);
	free(stack_a.data);
	free(stack_b.data);
	return (SUCCESS);
}
