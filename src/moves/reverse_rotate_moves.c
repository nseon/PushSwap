/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:07:38 by nseon             #+#    #+#             */
/*   Updated: 2025/01/08 14:48:49 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shift_utils.h"
#include "moves.h"
#include <unistd.h>

void	rra(t_stacks *test)
{
	int	temp;

	temp = test->a[test->sizea];
	shift_down(test->a, test->sizea);
	test->a[0] = temp;
	write (1, "rra\n", 4);
}

void	rrb(t_stacks *test)
{
	int	temp;

	temp = test->b[test->sizeb];
	shift_down(test->b, test->sizeb);
	test->b[0] = temp;
	write (1, "rrb\n", 4);
}

void	rrr(t_stacks *test)
{
	int	temp;

	temp = test->a[test->sizea];
	shift_down(test->a, test->sizea);
	test->a[0] = temp;
	temp = test->b[test->sizeb];
	shift_down(test->b, test->sizeb);
	test->b[0] = temp;
	write (1, "rrr\n", 4);
}
