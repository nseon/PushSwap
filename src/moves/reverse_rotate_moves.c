/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:07:38 by nseon             #+#    #+#             */
/*   Updated: 2025/01/23 13:02:44 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shift_utils.h"
#include "moves.h"
#include <unistd.h>

void	rra(t_stacks *stacks)
{
	int	temp;

	if (stacks->sizea > 1)
	{
		temp = stacks->a[stacks->sizea - 1];
		shift_down(stacks->a, stacks->sizea - 1);
		stacks->a[0] = temp;
		write (1, "rra\n", 4);
	}
}

void	rrb(t_stacks *stacks)
{
	int	temp;

	if (stacks->sizeb > 0)
	{
		temp = stacks->b[stacks->sizeb - 1];
		shift_down(stacks->b, stacks->sizeb - 1);
		stacks->b[0] = temp;
		write (1, "rrb\n", 4);
	}
}

void	rrr(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[stacks->sizea];
	shift_down(stacks->a, stacks->sizea - 1);
	stacks->a[0] = temp;
	temp = stacks->b[stacks->sizeb];
	shift_down(stacks->b, stacks->sizeb - 1);
	stacks->b[0] = temp;
	write (1, "rrr\n", 4);
}
