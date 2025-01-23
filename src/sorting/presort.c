/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:11:13 by nseon             #+#    #+#             */
/*   Updated: 2025/01/23 16:56:52 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "ft_printf.h"

int	square_root(double n)
{
	double	x;
	int		i;

	x = n;
	if (n <= 0)
		return (0);
	i = 0;
	while (i < 9)
	{
		x = (x + (n / x)) / 2;
		i++;
	}
	return ((int)(x + 0.5));
}

void	pre_tri(t_stacks *stacks)
{
	int	n;

	n = stacks->sizet / square_root((double)stacks->sizet);
	while (stacks->sizea > 3)
	{
		while (stacks->sizea > 3 && ((stacks->sizet - 2 > stacks->a[0] && stacks->a[0] > stacks->sizet - n)
				|| stacks->a[0] < n))
		{
			if (stacks->sizet - 2 > stacks->a[0] && stacks->a[0] > stacks->sizet - n)
			{
				pb(stacks);
				rb(stacks);
				n += 1;
			}
			else if (stacks->a[0] < n)
			{
				pb(stacks);
			}
		}
		ra(stacks);
	}
}
