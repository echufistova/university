/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:41:46 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/04 18:49:07 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		space(char c)
{
	if (c == '\n' || c == '\v' || c == '\t' ||
		c == ' ' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	g_atoi_i = 0;
	g_atoi_flag = 1;
	g_atoi_res = 0;
	while (space(str[g_atoi_i]))
		g_atoi_i++;
	if (str[g_atoi_i] == '-')
		g_atoi_flag = -1;
	if (str[g_atoi_i] == '-' || str[g_atoi_i] == '+')
	{
		if (str[g_atoi_i + 1] >= '0' && str[g_atoi_i + 1] <= '9')
			g_atoi_i++;
		else
			return (0);
	}
	while (str[g_atoi_i] >= '0' && str[g_atoi_i] <= '9')
	{
		if (g_atoi_res >= 9223372036854775807 && g_atoi_flag == 1)
			return (-1);
		else if (g_atoi_res > 9223372036854775807 && g_atoi_flag == -1)
			return (0);
		g_atoi_res = g_atoi_res * 10 + (str[g_atoi_i] - '0');
		g_atoi_i++;
	}
	return (g_atoi_res * g_atoi_flag);
}
