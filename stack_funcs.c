/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:59:29 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:12:14 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_clear(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}

void	ft_stack_add(t_stack *stack, int num)
{
	stack->data[(++stack->size) - 1] = num;
}

int	ft_stack_pop(t_stack *stack)
{
	int	value;

	value = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = 0;
	stack->size--;
	return (value);
}

void	ft_stack_switch_all(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	while (i < stack->size / 2)
	{
		temp = stack->data[(stack->size - 1) - i];
		stack->data[(stack->size - 1) - i] = stack->data[i];
		stack->data[i] = temp;
		i++;
	}
}

int	ft_get_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->size < 2)
		return (0);
	i = 1;
	min = 0;
	while (i < stack->size)
	{
		if (stack->data[i] < stack->data[min])
			min = i;
		i++;
	}
	return (min);
}
