/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:11:01 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:21:46 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_min(t_stack *stack)
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

static void	ft_mintotop(t_stack *stack)
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
}

void	ft_sort_random(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size != 0 && !ft_is_sorted(stack_a))
	{
		ft_mintotop(stack_a);
		if (ft_is_sorted(stack_a))
			break ;
		ft_stack_push(stack_a, stack_b, "pb\n");
	}
	while (stack_b->size != 0)
	{
		ft_stack_push(stack_b, stack_a, "pa\n");
	}
}
