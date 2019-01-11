/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:53:57 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 13:02:56 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		buf_length;

	i = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	j = ft_strlen(dst);
	buf_length = j;
	if (j >= dstsize)
		return (dstsize + ft_strlen(src));
	while (i < dstsize - buf_length - 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len);
}
