/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:58:02 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/17 15:08:52 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*print_negative_numbers(char *res, int n, int i)
{
	if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	if (n == -2147483648)
	{
		ft_strcpy(res, "-2147483648");
		return (res);
	}
	n = n * (-1);
	while (i > 0)
	{
		res[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	res[0] = '-';
	return (res);
}

static char		*print_positive_numbers(char *res, int n, int i)
{
	if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > 0)
	{
		res[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		np;
	int		i;

	np = n;
	i = 0;
	res = NULL;
	while (np != 0)
	{
		np = np / 10;
		i++;
	}
	if (n < 0)
		return (print_negative_numbers(res, n, i));
	if (n > 0)
		return (print_positive_numbers(res, n, i));
	res = ft_memalloc(2);
	res[0] = '0';
	return (res);
}
