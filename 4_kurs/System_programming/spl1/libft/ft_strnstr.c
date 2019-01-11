/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:32:05 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 14:09:57 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *podstr, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (podstr[i] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == podstr[0])
		{
			j = 0;
			while (podstr[j] == str[i + j] && podstr[j] != '\0' &&
					str[i + j] != '\0' && i + j < n)
				j++;
			if (ft_strlen(podstr) == j && j > 0)
				return ((char*)str + i);
		}
		i++;
	}
	return (0);
}
