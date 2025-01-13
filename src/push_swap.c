/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/13 19:05:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "moves.h"

t_stacks	*fill_struct(char **a, int argc, t_stacks *stacks)
{
	int			i;

	i = 0;
	stacks->sizea = argc;
	stacks->sizeb = argc;
	stacks->a = malloc(sizeof(int) * stacks->sizea);
	if (!stacks->a)
		return (NULL);
	stacks->b = malloc(sizeof(int) * stacks->sizeb);
	if (!stacks->b)
		return (NULL);
	while (i <= stacks->sizea)
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
	if(!stacks)
		return (0);
	fill_struct(argv, argc, stacks);
	ft_printf();

	return (0);
}
