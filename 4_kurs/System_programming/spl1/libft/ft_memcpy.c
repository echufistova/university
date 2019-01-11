/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:38:13 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 12:56:38 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*res;
	size_t			i;

	i = 0;
	source = (unsigned char*)src;
	res = (unsigned char*)dest;
	while (i != n)
	{
		res[i] = source[i];
		i++;
	}
	return (res);
}
