/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:24:06 by abourgeu          #+#    #+#             */
/*   Updated: 2016/11/25 15:46:41 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (!(tmp = (void *)malloc(sizeof(void *) * size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
