/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:23:01 by nseon             #+#    #+#             */
/*   Updated: 2025/01/15 10:06:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "shift_utils.h"
#include <unistd.h>

int	pa(t_stacks *stacks)
{
	stacks->sizea += 1;
	shift_down(stacks->a, stacks->sizea - 1);
	stacks->a[0] = stacks->b[0];
	shift_up(stacks->b, stacks->sizeb - 1);
	stacks->sizeb -= 1;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stacks *stacks)
{
	stacks->sizeb += 1;
	shift_down(stacks->b, stacks->sizeb - 1);
	stacks->b[0] = stacks->a[0];
	shift_up(stacks->a, stacks->sizea - 1);
	stacks->sizea -= 1;
	write(1, "pb\n", 3);
	return (1);
}
