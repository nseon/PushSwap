/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:12:03 by nseon             #+#    #+#             */
/*   Updated: 2025/01/27 18:24:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && '0' <= nptr[i] && nptr[i] <= '9')
	{
		if ((result * 10 + (nptr[i] - '0')) / 10 != result
			&& !(result == 214748364 && nptr[i] == '8' && sign == -1))
			return (0);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
