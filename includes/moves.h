/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:20:13 by nseon             #+#    #+#             */
/*   Updated: 2025/01/15 10:08:14 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	sizea;
	int	sizeb;
	int	sizet;
}	t_stacks;

int	pa(t_stacks *stacks);
int	pb(t_stacks *stacks);
int	sa(t_stacks *stacks);
int	sb(t_stacks *stacks);
int	ss(t_stacks *stacks);
int	ra(t_stacks *stacks);
int	rb(t_stacks *stacks);
int	rr(t_stacks *stacks);
int	rra(t_stacks *stacks);
int	rrb(t_stacks *stacks);
int	rrr(t_stacks *stacks);

#endif
