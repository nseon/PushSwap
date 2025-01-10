/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:44:26 by nseon             #+#    #+#             */
/*   Updated: 2025/01/10 15:53:30 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "moves.h"

void	fill_struct(char **a, int sizea)
{
	int			i;
	t_stacks	stacks;
	tab = malloc(sizeof(int) * sizea);
	if (!tab)
		return (NULL);
	while (i <= sizea)
	{
		tab[i] = ft_atoi(a[i]);
		i++;
	}

}

int	main(int argc, char **argv)
{

	return (0);
}
