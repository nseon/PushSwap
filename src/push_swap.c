/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/14 17:37:46 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "moves.h"

void	pre_tri(t_stacks *stacks)
{
	while (stacks->sizea > 0)
	{
		if (stacks->a[0] > 2 * (stacks->sizet / 3))
			ra(stacks);
		if (stacks->a[0] > stacks->a[1])
			sa(stacks);
		if (stacks->b[0] < stacks->b[1])
			sb(stacks);
		pb(stacks);
		if (stacks->b[0] < stacks->sizet / 3)
			rb(stacks);
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
	return (0);
}
