/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:10:18 by nseon             #+#    #+#             */
/*   Updated: 2025/01/24 17:40:08 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int			is_sort(t_stacks *stacks);
t_stacks	*fill_struct(char **a, int argc, t_stacks *stacks);
void		create_tab(char **input, int max, t_stacks *stacks);

#endif
