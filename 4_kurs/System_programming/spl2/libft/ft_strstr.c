/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:24:38 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 12:46:32 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *podstr)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (podstr[i] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (str[i] == podstr[0])
		{
			j = 0;
			while (str[i + j] == podstr[j] && podstr[j] != '\0')
				j++;
			if (ft_strlen(podstr) == j)
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
