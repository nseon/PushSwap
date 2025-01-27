/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/27 13:33:52 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "moves.h"
#include "sorting.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof (t_stacks));
	if (!stacks)
		return (0);
	fill_struct(argv + 1, argc - 1, stacks);
	if (!is_sort(stacks))
	{
		if (stacks->sizet == 2)
			sa(stacks);
		else if (stacks->sizet == 3)
			three_sort(stacks);
		else
		{
			pre_sort(stacks);
			if (!is_sort(stacks))
				three_sort(stacks);
			sort(stacks);
		}
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
