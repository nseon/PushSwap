/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:09:36 by nseon             #+#    #+#             */
/*   Updated: 2025/01/27 14:50:44 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	exit_free(t_stacks *stacks)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_sort(t_stacks *stacks)
{
	int	i;

	i = 1;
	while (i < stacks->sizea)
	{
		if (stacks->a[i] != stacks->a[i - 1] + 1)
			return (0);
		i++;
	}
	return (1);
}

void	index_mk(t_stacks *stacks, int	*list, int max)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < max)
	{
		j = 0;
		nb = 0;
		while (j < max)
		{
			if (list[j] < list[i])
				nb++;
			if (list[j] == list[i] && j != i)
			{
				free(list);
				exit_free(stacks);
			}
			j++;
		}
		stacks->a[i] = ++nb;
		i++;
	}
	free(list);
}

void	*create_tab(char **input, int max, t_stacks *stacks)
{
	int	i;
	int	*list;

	list = malloc(sizeof(int) * max);
	if (!list)
		exit_free(stacks);
	i = 0;
	while (i < max)
	{
		list[i] = ft_atoi(input[i]);
		if (list[i] == 0 && (ft_strlen(input[i]) != 1 || 0 != input[i][0]))
		{
			free(list);
			exit_free(stacks);
		}
		i++;
	}
	stacks->a = malloc(sizeof (int) * max);
	if (!stacks->a)
	{
		free(list);
		exit_free(stacks);
	}
	index_mk(stacks, list, max);
	return (NULL);
}

void	*fill_struct(char **a, int argc, t_stacks *stacks)
{
	stacks->sizea = argc;
	stacks->sizeb = 0;
	stacks->sizet = argc;
	stacks->a = NULL;
	stacks->b = malloc(sizeof (int) * stacks->sizet);
	if (!stacks->b)
		return (NULL);
	create_tab(a, argc, stacks);
	return (NULL);
}
