/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:26:37 by mavagner          #+#    #+#             */
/*   Updated: 2016/11/30 11:18:49 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_get_line(char **tetris)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		if (tetris[y][x] == '#')
			return (y);
		x++;
		if (x > 3)
		{
			x = 0;
			y++;
		}
	}
	return (-1);
}

int			ft_get_col(char **tetris)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (x < 4)
	{
		if (tetris[y][x] == '#')
			return (x);
		y++;
		if (y > 3)
		{
			y = 0;
			x++;
		}
	}
	return (-1);
}

void		ft_push_top(char **tetris)
{
	int		max_y;
	int		y;
	char	*tmp;

	max_y = ft_get_line(tetris);
	y = 0;
	while (max_y < 4)
	{
		tmp = tetris[y];
		tetris[y] = tetris[max_y];
		tetris[max_y] = tmp;
		y += 1;
		max_y += 1;
	}
}

void		ft_push_left(char **tetris)
{
	int		max_x;
	int		x;
	int		y;
	char	tmp;

	max_x = ft_get_col(tetris);
	x = 0;
	y = 0;
	while (max_x < 4)
	{
		tmp = tetris[y][x];
		tetris[y][x] = tetris[y][max_x];
		tetris[y][max_x] = tmp;
		y += 1;
		if (4 <= y)
		{
			y = 0;
			x += 1;
			max_x += 1;
		}
	}
}

void		ft_put_letter(char **tetris, char letter)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		if (tetris[y][x] == '#')
			tetris[y][x] = letter;
		x += 1;
		if (x > 3)
		{
			x = 0;
			y += 1;
		}
	}
}
