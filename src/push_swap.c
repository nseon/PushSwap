/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/23 17:10:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "moves.h"
#include "sorting.h"

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
	while (i + 1 <= stacks->sizet)
	{
		stacks->a[i] = ft_atoi(a[i]);
		i++;
	}
	return (NULL);
}

int	is_sort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->sizea)
	{
		if (stacks->a[i] != i + 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof (t_stacks));
	if (!stacks)
		return (0);
	fill_struct(argv + 1, argc - 1, stacks);
	if (!is_sort(stacks))
	{
		if (stacks->sizet == 3)
			three_sort(stacks);
		else
		{
			pre_tri(stacks);
			three_sort(stacks);
			pa(stacks);
			ra(stacks);
			tri(stacks);
		}
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
