/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:09:36 by nseon             #+#    #+#             */
/*   Updated: 2025/01/24 17:47:41 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

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
	j = 0;
	while (i < max)
	{
		nb = 0;
		while (list[j])
		{
			if (list[j] < list[i])
				nb++;
			if (list[j] == list[i] && j == i)
			{
				free(list);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		ft_printf("%d\n", nb);
		stacks->a[i] = nb;
		i++;
	}
}

void	*create_tab(char **input, int max, t_stacks *stacks)
{
	int	i;
	int	*list;

	list = malloc(sizeof(int) * max);
	if (!list)
		return (NULL);
	i = 0;
	while (i < max)
	{
		list[i] = ft_atoi(input[i]);
		i++;
	}
	stacks->a = malloc(sizeof (int) * max);
	if (!stacks->a)
		return (NULL);
	index_mk(stacks, list, max);
	return (NULL);
}

t_stacks	*fill_struct(char **a, int argc, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->sizea = argc;
	stacks->sizeb = 0;
	stacks->sizet = argc;
	stacks->a = malloc(sizeof (int) * stacks->sizet);
	if (!stacks->a)
		return (NULL);
	stacks->b = malloc(sizeof (int) * stacks->sizet);
	if (!stacks->b)
		return (free(stacks->a), NULL);
	while (i < stacks->sizet)
	{
		stacks->a[i] = ft_atoi(a[i]);
		i++;
	}
	return (NULL);
}
