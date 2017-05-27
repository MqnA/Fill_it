/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:08:24 by mavagner          #+#    #+#             */
/*   Updated: 2016/12/01 18:28:35 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_clean_map(char **map, int size, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (map[i][j] == c)
			map[i][j] = '.';
		j++;
		if (j >= size)
		{
			j = 0;
			i++;
		}
	}
}

void		ft_free_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void		ft_fill_map(int size, char **map)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (size > i)
	{
		map[i][j] = '.';
		j++;
		if (size <= j)
		{
			map[i][j] = '\0';
			i++;
			j = 0;
		}
	}
}

char		**ft_create_map(int size)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (size > i)
	{
		if (!(map[i] = ft_strnew(size + 1)))
			return (NULL);
		i++;
	}
	ft_fill_map(size, map);
	return (map);
}
