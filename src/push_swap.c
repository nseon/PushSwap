/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/21 18:06:26 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "moves.h"

void	pre_tri(t_stacks *stacks)
{
	int	n;

	n = stacks->sizet / 20;
	while (stacks->sizea > 0)
	{
		while (stacks->sizea > 0 && (stacks->a[0] > stacks->sizet - n || stacks->a[0] < n))
		{
			if (stacks->a[0] > stacks->sizet - n)
			{
				pb(stacks);
				rb(stacks);
				n += 1;
			}
			if (stacks->a[0] < n)
			{
				pb(stacks);
			}
		}
		ra(stacks);
	}
}

int	search_next(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->b[i] != stacks->sizeb && i < stacks->sizeb)
		i++;
	return (i);
}

void	tri(t_stacks *stacks)
{
	int	n;

	n = 0;
	while (stacks->b[0] != stacks->sizet - n)
	{
		if (stacks->b[0] > stacks->a[stacks->sizea - 1])
		{
			pa(stacks);
			ra(stacks);
		}
		rrb(stacks);
	}
	pa(stacks);
	while (stacks->sizeb > 0)
	{
		while (search_next(stacks) >= stacks->sizeb)
			ra(stacks);
		if (search_next(stacks) <= stacks->sizeb / 2)
		{
			while (stacks->b[0] != stacks->sizeb)
				rb(stacks);
		}
		else
		{
			while (stacks->b[0] != stacks->sizeb)
				rrb(stacks);
		}
		pa(stacks);
	}
}

t_stacks	*fill_struct(char **a, int argc, t_stacks *stacks)
{
	int			i;

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
	while (i + 1 <= stacks->sizea)
	{
		stacks->a[i] = ft_atoi(a[i]);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof (t_stacks));
	if (!stacks)
		return (0);
	fill_struct(argv + 1, argc - 1, stacks);
	pre_tri(stacks);
	tri(stacks);
	return (0);
}
