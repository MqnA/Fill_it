/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:26:22 by abourgeu          #+#    #+#             */
/*   Updated: 2016/12/01 18:41:21 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				ft_split_tetrim(char *map, t_fillit *fillit, size_t count)
{
	char		**tetris;
	size_t		i;

	if ((tetris = ft_strsplit(map, '\n')) == NULL)
		return (0);
	fillit->tetris = (char ***)malloc(sizeof(char **) * count);
	if (fillit->tetris == NULL)
		return (0);
	free(map);
	i = 0;
	while (i < count)
	{
		fillit->tetris[i] = &tetris[i * 4];
		ft_push_top(fillit->tetris[i]);
		ft_push_left(fillit->tetris[i]);
		ft_put_letter(fillit->tetris[i], 'A' + i);
		i += 1;
	}
	return (1);
}

int				check_tetris(char *map)
{
	int			touch;
	int			i;
	int			sharp;

	sharp = 0;
	touch = 0;
	i = 0;
	while ((map[i] != '\n' || map[i + 1] != '\n') && (map[i + 1] != '\0'))
	{
		if (map[i] == '#')
		{
			sharp += 1;
			touch += (map[i - 5] == '#') ? 1 : 0;
			touch += (map[i - 1] == '#') ? 1 : 0;
			touch += (map[i + 5] == '#') ? 1 : 0;
			touch += (map[i + 1] == '#') ? 1 : 0;
		}
		i++;
	}
	if (touch < 6 || sharp != 4)
		return (0);
	return (1);
}

int				check_map(char *map, int i, int j)
{
	if (map[0] == '\0')
		return (0);
	while (map[i + j * 21])
	{
		if (i % 5 == 4 && map[i + (j * 21)] != '\n')
			return (0);
		else if (map[i + j * 21] != '.' && map[i + j * 21] != '#' && i % 5 != 4)
			return (0);
		i += 1;
		if (i == 20)
		{
			if (map[i + j * 21] == '\0')
				return (1);
			if (map[i + j * 21] != '\n')
				return (0);
			i = 0;
			j += 1;
			if (map[i + j * 21] != '.' && map[i + j * 21] != '#')
				return (0);
		}
	}
	if (i % 21 != 0)
		return (0);
	return (1);
}

char			*read_map(char *av)
{
	int			ret;
	int			fd;
	char		*map;
	char		buf[BUFF_SIZE + 1];

	if (!(map = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	map[0] = '\0';
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		if (!(map = ft_strjoin_free(map, buf)))
			return (NULL);
	}
	close(fd);
	return (map);
}

int				ft_check(char *file, t_fillit *fillit)
{
	char		*map;
	size_t		i;

	fillit->count = 0;
	if (NULL == (map = read_map(file)))
		return (0);
	if (check_map(map, 0, 0) == 0)
		return (0);
	i = 0;
	while (i * 21 < ft_strlen(map) && map[i * 21] != '\0')
	{
		if (check_tetris(&map[i * 21]) == 0)
			return (0);
		fillit->count += 1;
		i++;
	}
	if (ft_split_tetrim(map, fillit, fillit->count) == 0)
		return (0);
	return (1);
}
