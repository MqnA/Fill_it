/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:15:04 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/01 18:39:39 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

#define Y  p[1]
#define X  p[0]

int			ft_put_tetrim(t_fillit *fillit, int tetrim, int x, int y)
{
	int		p[2];
	int		placed;

	p[0] = x;
	p[1] = y;
	placed = 0;
	while (y < fillit->map_size && y - p[1] < 4)
	{
		if (ft_isalpha(MAP[y][x]) && ft_isalpha(TETRIS[tetrim][y - Y][x - X]))
			return (0);
		if (MAP[y][x] == '.' && ft_isalpha(TETRIS[tetrim][y - Y][x - X]))
		{
			MAP[y][x] = TETRIS[tetrim][y - Y][x - X];
			placed++;
			if (placed == 4)
				return (1);
		}
		x++;
		if (x >= fillit->map_size || x - X >= 4)
		{
			y++;
			x = X;
		}
	}
	return (0);
}

int			ft_fillit(t_fillit *fillit, int tetrim, int x, int y)
{
	if (tetrim >= fillit->count)
		return (1);
	while (y < fillit->map_size)
	{
		if (ft_put_tetrim(fillit, tetrim, x, y) == 1)
		{
			if (ft_fillit(fillit, tetrim + 1, 0, 0) == 1)
				return (1);
		}
		ft_clean_map(fillit->map, fillit->map_size, 'A' + tetrim);
		x++;
		if (fillit->map_size <= x)
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

int			ft_resolve(t_fillit *fillit)
{
	fillit->map_size = 2;
	if (NULL == (fillit->map = ft_create_map(fillit->map_size)))
		return (0);
	while (ft_fillit(fillit, 0, 0, 0) == 0)
	{
		ft_free_map(fillit->map, fillit->map_size);
		fillit->map_size += 1;
		if (NULL == (fillit->map = ft_create_map(fillit->map_size)))
			return (0);
	}
	return (1);
}
