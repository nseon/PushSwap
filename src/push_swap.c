/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/20 18:20:52 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "moves.h"

void	pre_tri(t_stacks *stacks)
{
	int	count_red;

	count_red = 0;
	while (stacks->sizea > 0)
	{
		if (stacks->b[0] < stacks->sizet / 3)
			rb(stacks);
		while (stacks->a[0] > 2 * (stacks->sizet / 3) && count_red < stacks->sizea)
		{
			ra(stacks);
			count_red++;
		}
		pb(stacks);
	}
}

void	sortpart(t_stacks *stacks)
{
	int	i;
	int	j;

	j = 0;
	i = stacks->sizea - 1;
	if (stacks->b[0] > stacks->a[i])
	{
		pa(stacks);
		ra(stacks);
	}
	else if (stacks->b[0] < stacks->a[0])
		pa(stacks);
	else if (i > 0)
	{
		while (!(stacks->a[i - 1] <= stacks->b[0] && stacks->b[0] <= stacks->a[i]))
		{
			i--;
		}
		while (j < i)
		{
			ra(stacks);
			j++;
		}
		pa(stacks);
		while (j > 0)
		{
			rra(stacks);
			if (stacks->a[stacks->sizea - 1])
			j--;
		}
	}
}

void	sort(t_stacks *stacks)
{
	int	n;
	int	count;

	n = 6;
	while (stacks->sizeb > 0)
	{
		count = 0;
		while (stacks->b[0] >= ((n / 2) - 1) * stacks->sizet / 3 && count <= stacks->sizet / 6)
		{
			if (n * stacks->sizet / 6 >= stacks->b[0] && stacks->b[0] >= (n - 1) * stacks->sizet / 6)
				sortpart(stacks);
			else
			{
				rb(stacks);
				count++;
			}
		}
		while (stacks->b[stacks->sizeb - 1] >= ((n / 2) - 1) * stacks->sizet / 3 && stacks->sizeb > 0)
		{
			rrb(stacks);
			sortpart(stacks);
		}
		n -= 2;
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
	sort(stacks);
	return (0);
}
