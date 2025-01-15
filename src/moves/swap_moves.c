/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:11 by nseon             #+#    #+#             */
/*   Updated: 2025/01/15 10:26:44 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <unistd.h>

void	sa(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	write(1, "ss\n", 3);
}
