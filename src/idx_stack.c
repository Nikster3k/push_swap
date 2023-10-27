/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:23:30 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/26 18:23:38 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_indx(t_stack *stack, int value)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] < value && stack->data[i] != value)
			count++;
		i++;
	}
	return (count);
}

int	ft_make_idx_stack(t_stack *stack_a, t_stack *stack_b, t_stack *copy)
{
	int	i;

	copy->data = ft_calloc(sizeof(int), stack_a->size);
	if (copy->data == NULL)
	{
		free(stack_a);
		free(stack_b);
		return (MALLOC_FAIL);
	}
	copy->size = stack_a->size;
	i = 0;
	while (i < stack_a->size)
	{
		copy->data[i] = ft_get_indx(stack_a, stack_a->data[i]) + 1;
		i++;
	}
	return (SUCCESS);
}
