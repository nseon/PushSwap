/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:55:45 by nseon             #+#    #+#             */
/*   Updated: 2025/01/08 14:48:55 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shift_utils.h"
#include "moves.h"
#include <unistd.h>

void	ra(t_stacks *test)
{
	int	temp;

	temp = test->a[0];
	shift_up(test->a, test->sizea);
	test->a[test->sizea] = temp;
	write (1, "ra\n", 3);
}

void	rb(t_stacks *test)
{
	int	temp;

	temp = test->b[0];
	shift_up(test->b, test->sizeb);
	test->b[test->sizeb] = temp;
	write (1, "rb\n", 3);
}

void	rr(t_stacks *test)
{
	int	temp;

	temp = test->a[0];
	shift_up(test->a, test->sizea);
	test->a[test->sizea] = temp;
	temp = test->b[0];
	shift_up(test->b, test->sizeb);
	test->b[test->sizeb] = temp;
	write (1, "rr\n", 3);
}
