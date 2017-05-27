/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:50:36 by mavagner          #+#    #+#             */
/*   Updated: 2016/12/01 18:29:02 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int					main(int ac, char **av)
{
	t_fillit		*fillit;
	size_t			i;

	i = 0;
	if (ac < 2 || ac > 2)
	{
		ft_putstr("man");
		return (-1);
	}
	if (ac == 2)
	{
		if (!(fillit = (t_fillit *)malloc(sizeof(t_fillit))))
			return (0);
		if (ft_check(av[1], fillit) == 0)
		{
			write(1, "error\n", 6);
			return (1);
		}
		if (ft_resolve(fillit) == 0)
		{
			write(1, "error\n", 6);
			return (1);
		}
		ft_print(fillit);
	}
}
