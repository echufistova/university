/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:47:56 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/04 15:54:42 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	if (s)
	{
		j = ft_strlen(s);
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (s[i] != '\0')
		{
			while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
				j--;
		}
		if (!(res = ft_strsub(s, i, j - i)))
			return (NULL);
		return (res);
	}
	return (NULL);
}
