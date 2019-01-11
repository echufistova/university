/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:31:13 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 14:41:27 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_mmap(int *tab, int length, int (*f)(int))
{
	int i;
	int *buf;

	i = 0;
	buf = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		buf[i] = f(tab[i]);
		i++;
	}
	return (buf);
}
