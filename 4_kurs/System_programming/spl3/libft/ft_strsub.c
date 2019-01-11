/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:42:53 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/03 20:31:47 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	i = 0;
	if (s)
	{
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
		{
			return (NULL);
		}
		while (i < len)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
