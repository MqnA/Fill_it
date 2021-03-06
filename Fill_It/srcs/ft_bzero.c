/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:59:48 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/25 15:46:02 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_bzero(void *s, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = s;
	while (i < len)
	{
		tmp[i] = 0;
		i++;
	}
}
