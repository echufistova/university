/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:55:53 by ychufist          #+#    #+#             */
/*   Updated: 2018/03/29 18:40:29 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
//	printf("%s - %zd\n", str1, ft_strlen(str1));
//    printf("%s - %zd\n", str2, ft_strlen(str2));
//	printf("%zd\n", ft_strlen(str1));
//    printf("%zd\n", ft_strlen(str2));
	if (ft_strlen(str1) != 0 && ft_strlen(str2) != 0)
	{
		s1 = (unsigned char *)str1;
		s2 = (unsigned char *)str2;
		while (s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
		return (s1[i] - s2[i]);
	}
	return (3);
}
