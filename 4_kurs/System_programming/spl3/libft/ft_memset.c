/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:32:26 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 12:55:21 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*k;
	size_t			a;

	k = (unsigned char *)b;
	a = 0;
	while (a < len)
	{
		k[a] = (char)c;
		a++;
	}
	return (k);
}
