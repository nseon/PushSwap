/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:11 by nseon             #+#    #+#             */
/*   Updated: 2025/01/08 14:49:08 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <unistd.h>

void	sa(t_stacks *test)
{
	int	temp;

	temp = test->a[0];
	test->a[0] = test->a[1];
	test->a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *test)
{
	int	temp;

	temp = test->b[0];
	test->b[0] = test->b[1];
	test->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *test)
{
	int	temp;

	temp = test->a[0];
	test->a[0] = test->a[1];
	test->a[1] = temp;
	temp = test->b[0];
	test->b[0] = test->b[1];
	test->b[1] = temp;
	write(1, "ss\n", 3);
}
