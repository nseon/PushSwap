/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:20:13 by nseon             #+#    #+#             */
/*   Updated: 2025/01/08 09:47:13 by nseon            ###   ########.fr       */
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
}	t_stacks;

void	pa(t_stacks *test);
void	pb(t_stacks *test);
void	sa(t_stacks *test);
void	sb(t_stacks *test);
void	ss(t_stacks *test);
void	ra(t_stacks *test);
void	rb(t_stacks *test);
void	rr(t_stacks *test);
void	rra(t_stacks *test);
void	rrb(t_stacks *test);
void	rrr(t_stacks *test);

#endif
