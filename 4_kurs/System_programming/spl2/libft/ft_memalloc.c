/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:17:09 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/03 20:28:51 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *arr;

	arr = (void*)malloc(sizeof(void) * size);
	if (arr == NULL)
		return (0);
	ft_bzero((void *)arr, size);
	return ((void *)arr);
}
