/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:17:27 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 17:18:19 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_mean(t_stack *stack)
{
	int	sum;
	int	i;

	if (stack->size == 0)
		return (0);
	sum = 0;
	i = 0;
	while (i < stack->size)
	{
		sum += stack->data[i];
		i++;
	}
	return (sum / stack->size);
}

int	ft_get_max(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->size < 2)
		return (0);
	i = 1;
	max = 0;
	while (i < stack->size)
	{
		if (stack->data[i] > stack->data[max])
			max = i;
		i++;
	}
	return (max);
}