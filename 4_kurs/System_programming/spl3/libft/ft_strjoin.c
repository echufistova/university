/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:44:22 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/03 20:32:40 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			len;
	char		*res;

	i = 0;
	if (s1 && s2)
	{
		len = strlen(s1) + strlen(s2) + 1;
		res = (char*)malloc(sizeof(char) * len);
		if (res == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[i - strlen(s1)] != '\0')
		{
			res[i] = s2[i - strlen(s1)];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
