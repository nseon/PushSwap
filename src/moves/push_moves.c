/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:23:01 by nseon             #+#    #+#             */
/*   Updated: 2025/01/10 15:55:14 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "shift_utils.h"
#include <unistd.h>

void	pa(t_stacks *stacks)
{
	shift_down(stacks->a, stacks->sizea);
	stacks->a[0] = stacks->b[0];
	stacks->sizea += 1;
	shift_up(stacks->b, stacks->sizeb);
	stacks->sizeb -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	shift_down(stacks->b, stacks->sizeb);
	stacks->b[0] = stacks->a[0];
	stacks->sizeb += 1;
	shift_up(stacks->a, stacks->sizea);
	stacks->sizea -= 1;
	write(1, "pa\n", 3);
}
