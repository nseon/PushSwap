/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:06 by nseon             #+#    #+#             */
/*   Updated: 2025/01/07 16:34:27 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	shift_down(int	*tab, int i)
{
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
}

void	shift_up(int *tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		tab[j] = tab[j + 1];
		j++;
	}
}
