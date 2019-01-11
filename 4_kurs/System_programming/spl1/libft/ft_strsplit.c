/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:17:25 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/17 17:22:09 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (s && (res = (char**)ft_memalloc(sizeof(char*) * (ft_cw(s, c) + 1))))
	{
		i = 0;
		k = -1;
		while (s[i] != '\0')
		{
			if (ft_cl(s, c, i))
			{
				res[++k] = (char*)ft_memalloc(sizeof(char)
						* (ft_cl(s, c, i) + 1));
				j = 0;
				while (s[i] != '\0' && s[i] != c)
					res[k][j++] = s[i++];
			}
			else
				i++;
		}
		return (res);
	}
	return (0);
}
