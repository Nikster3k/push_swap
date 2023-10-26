/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:11:01 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/26 18:54:54 by nsassenb         ###   ########.fr       */
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

void	ft_sort_smaller(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	while (stack_a->size != 0 && !ft_is_sorted(stack_a))
	{
		if (ft_get_max_idx(stack_a) == stack_a->size - 1)
			ft_stack_rotate(stack_a, "ra\n");
		while (stack_a->data[ft_get_max_idx(stack_a)]
			<= stack_a->data[stack_a->size - 1] && ft_get_max_idx(stack_a) == 0)
			ft_stack_rotate(stack_a, "ra\n");
		if (stack_a->size > 2 && stack_a->data[stack_a->size - 1]
			> stack_a->data[stack_a->size - 2])
			ft_stack_swap(stack_a, "sa\n");
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
