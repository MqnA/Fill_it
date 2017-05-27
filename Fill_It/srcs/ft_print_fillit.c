/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:35:22 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/01 18:27:42 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_clear_fillit(t_fillit *fillit)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < fillit->count)
	{
		free(fillit->tetris[i][j]);
		j += 1;
		if (j >= 4)
		{
			j = 0;
			i += 1;
		}
	}
	free(fillit->tetris);
	ft_free_map(fillit->map, fillit->map_size);
	free(fillit);
}

void		ft_print(t_fillit *fillit)
{
	int		i;

	i = 0;
	while (i < fillit->map_size)
	{
		ft_putendl(fillit->map[i]);
		i += 1;
	}
	ft_clear_fillit(fillit);
}
