/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:17:55 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/03 20:32:18 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	arr = (char*)malloc(sizeof(char) * (size + 1));
	if (arr == NULL)
		return (0);
	ft_bzero(arr, size + 1);
	return (arr);
}
