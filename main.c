/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:33 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/20 20:04:27 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int errnum)
{
	ft_printf("Error\n");
	return (errnum);
}

int	ft_fill_stack(char *args, t_stack *stack, int size)
{
	long	value;
	int		i;

	i = 0;
	while (i < size)
	{
		value = ft_atoi(args);
		if (value > INT_MAX || value < INT_MIN)
			return (INT_OVERFLOW);
		stack->data[i++] = value;
		while (*args && *args != 32)
			args++;
		args++;
	}
	stack->size = size;
	return (SUCCESS);
}

int	ft_allocate_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->data = ft_calloc(size, sizeof(int));
	if (stack_a->data == NULL)
		return (MALLOC_FAIL);
	stack_a->size = size;
	stack_b->data = ft_calloc(size, sizeof(int));
	if (stack_b->data == NULL)
	{
		free(stack_a->data);
		return (MALLOC_FAIL);
	}
	stack_b->size = 0;
	return (SUCCESS);
}

int	ft_init_stacks(char *args, t_stack *stack_a, t_stack *stack_b, int size)
{
	if (ft_allocate_stacks(stack_a, stack_b, size))
		return (MALLOC_FAIL);
	if (ft_fill_stack(args, stack_a, size))
	{
		free(args);
		free(stack_a->data);
		free(stack_b->data);
		return (ft_error(INT_OVERFLOW));
	}
	// free(args);
	if (ft_check_dup(stack_a))
	{
		free(stack_a->data);
		free(stack_b->data);
		return (ft_error(HAS_DUPLICATE));
	}
	ft_stack_switch_all(stack_a);
	return (SUCCESS);
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_mintotop(t_stack *stack)
{
	int	min_idx;
	int	min;

	min_idx = ft_get_min(stack);
	min = stack->data[min_idx];
	while (stack->data[stack->size - 1] != min)
	{
		if (min_idx >= stack->size / 2)
			ft_stack_rotate(stack, "ra\n");
		else
			ft_stack_rev_rotate(stack, "rra\n");
	}
	return (SUCCESS);
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
	//ft_printf("Combined: \"%s\" Count: %i\n", args, count);
	while (stack_a.size != 0 && !ft_is_sorted(&stack_a))
	{
		ft_mintotop(&stack_a);
		if (ft_is_sorted(&stack_a))
			break ;
		ft_stack_push(&stack_a, &stack_b, "pb\n");
	}
	while (stack_b.size != 0)
	{
		ft_stack_push(&stack_b, &stack_a, "pa\n");
	}
	
	// ft_printf("stack a: \n");
	// int x = count;
	// while (x--)
	// 	ft_printf("%i\n", stack_a.data[x]);
	// ft_printf("stack b: \n");
	// x = count;
	// while (x--)
	// 	ft_printf("%i\n", stack_b.data[x]);
	// ft_printf("Min: %i\n", ft_get_min(&stack_a));
	// ft_printf("Is sorted %i\n", ft_is_sorted(&stack_a));
	free(args);
	free(stack_a.data);
	free(stack_b.data);
	return (SUCCESS);
}
