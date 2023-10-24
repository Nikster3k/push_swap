/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:25:36 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/24 14:25:43 by nsassenb         ###   ########.fr       */
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

int	ft_init_stacks(
	char *args, t_stack *stack_a, t_stack *stack_b, int size)
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
	free(args);
	if (ft_check_dup(stack_a))
	{
		free(stack_a->data);
		free(stack_b->data);
		return (ft_error(HAS_DUPLICATE));
	}
	ft_stack_switch_all(stack_a);
	return (SUCCESS);
}
