/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:09:16 by nsassenb          #+#    #+#             */
/*   Updated: 2023/10/19 18:31:49 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_error_free(char *err)
{
	free(err);
	return (NULL);
}

char	*ft_join_argv(int argc, char **argv)
{
	char	*comb;
	char	*temp;
	int		i;

	i = 0;
	comb = NULL;
	while (++i < argc)
	{
		temp = ft_strjoin(comb, argv[i]);
		if (temp == NULL)
			return (ft_error_free(comb));
		free(comb);
		comb = temp;
		if (i != argc - 1)
		{
			temp = ft_strjoin(comb, " ");
			if (temp == NULL)
				return (ft_error_free(comb));
			free(comb);
			comb = temp;
		}
	}
	return (comb);
}

int	ft_check_args(char *args, int *count)
{
	while (*args)
	{
		if (*args == '+' || *args == '-')
			args++;
		if (!ft_isdigit(*args))
			return (BAD_ARGS);
		while (ft_isdigit(*args))
			args++;
		if (*args == 32)
		{
			args++;
			if (*args == '\0')
				return (BAD_ARGS);
			else
				(*count)++;
		}
	}
	(*count)++;
	return (SUCCESS);
}

int	ft_check_dup(t_stack *stack)
{
	int	i;
	int	x;

	i = 0;
	while (i < stack->size)
	{
		x = i + 1;
		while (x < stack->size)
		{
			if (stack->data[i] == stack->data[x])
				return (HAS_DUPLICATE);
			x++;
		}
		i++;
	}
	return (SUCCESS);
}
