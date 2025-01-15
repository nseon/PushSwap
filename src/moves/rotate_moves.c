/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:55:45 by nseon             #+#    #+#             */
/*   Updated: 2025/01/15 10:26:48 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shift_utils.h"
#include "moves.h"
#include <unistd.h>

void	ra(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	shift_up(stacks->a, stacks->sizea - 1);
	stacks->a[stacks->sizea - 1] = temp;
	write (1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[0];
	shift_up(stacks->b, stacks->sizeb - 1);
	stacks->b[stacks->sizeb - 1] = temp;
	write (1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	shift_up(stacks->a, stacks->sizea);
	stacks->a[stacks->sizea - 1] = temp;
	temp = stacks->b[0];
	shift_up(stacks->b, stacks->sizeb);
	stacks->b[stacks->sizeb - 1] = temp;
	write (1, "rr\n", 3);
}
