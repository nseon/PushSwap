/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:23:01 by nseon             #+#    #+#             */
/*   Updated: 2025/01/08 14:48:45 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "shift_utils.h"
#include <unistd.h>

void	pa(t_stacks *test)
{
	shift_down(test->a, test->sizea);
	test->a[0] = test->b[0];
	test->sizea += 1;
	shift_up(test->b, test->sizeb);
	test->sizeb -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *test)
{
	shift_down(test->b, test->sizeb);
	test->b[0] = test->a[0];
	test->sizeb += 1;
	shift_up(test->a, test->sizea);
	test->sizea -= 1;
	write(1, "pa\n", 3);
}
