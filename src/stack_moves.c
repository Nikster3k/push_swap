/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:56:55 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/23 10:56:42 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack *stack, char *msg)
{
	int	temp;

	ft_printf(msg);
	if (stack->size < 2)
		return ;
	temp = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = stack->data[stack->size - 2];
	stack->data[stack->size - 2] = temp;
}

void	ft_stack_rotate(t_stack *stack, char *msg)
{
	int	temp;

	ft_printf(msg);
	if (stack->size < 2)
		return ;
	temp = stack->data[stack->size - 1];
	ft_memmove(
		&stack->data[1], &stack->data[0], sizeof(int) * (stack->size - 1));
	stack->data[0] = temp;
}

void	ft_stack_rev_rotate(t_stack *stack, char *msg)
{
	int	temp;

	ft_printf(msg);
	if (stack->size < 2)
		return ;
	temp = stack->data[0];
	ft_memmove(
		&stack->data[0], &stack->data[1], sizeof(int) * (stack->size - 1));
	stack->data[stack->size - 1] = temp;
}

void	ft_stack_push(t_stack *lhs, t_stack *rhs, char *msg)
{
	ft_printf(msg);
	if (lhs->size < 1)
		return ;
	ft_stack_add(rhs, ft_stack_pop(lhs));
}
