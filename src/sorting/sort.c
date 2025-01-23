/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:11:23 by nseon             #+#    #+#             */
/*   Updated: 2025/01/23 13:06:50 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <unistd.h>
#include "ft_printf.h"

int	search_next(t_stacks *stacks, int n)
{
	int	i;

	i = 0;
	while (stacks->b[i] != stacks->sizet - n && i < stacks->sizeb)
		i++;
	return (i);
}

void	biggest(t_stacks *stacks, int nb, int direction)
{
	while (stacks->b[0] != nb)
	{
		if (stacks->b[0] > stacks->a[stacks->sizea - 1]
			|| stacks->a[stacks->sizea - 1] == stacks->sizet)
		{
			pa(stacks);
			ra(stacks);
		}
		else
		{
			if (!direction)
				rrb(stacks);
			else if (direction)
				rb(stacks);
		}
	}
	pa(stacks);
}

void	tri(t_stacks *stacks)
{
	int	n;

	n = 1;
	biggest(stacks, stacks->sizet, 0);
	while (stacks->sizeb > 0 || stacks->a[stacks->sizea - 1] != stacks->sizet)
	{
		while (stacks->a[stacks->sizea - 1] == stacks->a[0] - 1)
		{
			rra(stacks);
			n++;
		}
		if (search_next(stacks, n) <= stacks->sizeb / 2
			 && stacks->sizeb > 0)
		{
			biggest(stacks, stacks->sizet - n, 1);
			n++;
		}
		else if (stacks->sizeb > 0)
		{
			biggest(stacks, stacks->sizet - n, 0);
			n++;
		}
	}
}
