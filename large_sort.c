/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:09:09 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:57 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_maxtotop(t_stack *stack)
{
	int	max_idx;
	int	max;

	max_idx = ft_get_max(stack);
	max = stack->data[max_idx];
	while (stack->data[stack->size - 1] != max)
	{
		if (max_idx >= stack->size / 2)
			ft_stack_rotate(stack, "rb\n");
		else
			ft_stack_rev_rotate(stack, "rrb\n");
	}
}

static void	ft_sort_a(t_stack *stack_b, t_stack *stack_a)
{
	int	max_idx;
	int	max;

	max_idx = ft_get_max(stack_b);
	max = stack_b->data[max_idx];
	while (stack_b->data[stack_b->size - 1] != max)
	{
		if (ft_get_max(stack_a) == 0)
		{
			ft_stack_push(stack_b, stack_a, "pa\n");
			ft_stack_rotate(stack_a, "ra\n");
		}
		else if (stack_b->data[stack_b->size - 1] > stack_a->data[0])
		{
			ft_stack_push(stack_b, stack_a, "pa\n");
			ft_stack_rotate(stack_a, "ra\n");
		}
		else
		{
			if (max_idx >= stack_b->size / 2)
				ft_stack_rotate(stack_b, "rb\n");
			else
				ft_stack_rev_rotate(stack_b, "rrb\n");
		}
	}
}

static int	ft_cointains_smaller(t_stack *stack, int numb)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i++] < numb)
			return (1);
	}
	return (0);
}

static void	ft_divide(t_stack *stack_a, t_stack *stack_b, int divider, int step)
{
	if (stack_a->size == 0 || ft_is_sorted(stack_a))
		return ;
	while (stack_a->size > 0 && ft_cointains_smaller(stack_a, divider)
		&& !ft_is_sorted(stack_a))
	{
		if (stack_a->data[stack_a->size - 1] < divider)
		{
			ft_stack_push(stack_a, stack_b, "pb\n");
			ft_stack_rotate(stack_b, "rb\n");
		}
		else if (stack_a->data[stack_a->size - 1] < divider + step)
		{
			ft_stack_push(stack_a, stack_b, "pb\n");
		}
		else
			ft_stack_rotate(stack_a, "ra\n");
	}
	ft_divide(stack_a, stack_b, divider + step, step);
}

void	ft_sort_large(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 250)
		ft_divide(stack_a, stack_b,
			ft_get_mean(stack_a) / 8, ft_get_mean(stack_a) / 8);
	else
		ft_divide(stack_a, stack_b,
			ft_get_mean(stack_a) / 2, ft_get_mean(stack_a) / 2);
	ft_maxtotop(stack_b);
	ft_stack_push(stack_b, stack_a, "pa\n");
	while (stack_b->size)
	{
		ft_sort_a(stack_b, stack_a);
		ft_stack_push(stack_b, stack_a, "pa\n");
		while (ft_get_max(stack_a) != 0
			&& stack_a->data[0] > stack_b->data[ft_get_max(stack_b)])
		{
			ft_stack_rev_rotate(stack_a, "rra\n");
		}
	}
}
