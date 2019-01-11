/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:56:47 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 12:19:29 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	if (n != 0)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && i < n)
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
		if ((s1[i] == '\0' || s2[i] == '\0') && i == n)
			return (s1[i - 1] - s2[i - 1]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
	}
	return (0);
}
