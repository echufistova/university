/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:00:05 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/03 20:31:02 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb == -2147483648)
	{
		nb = nb % 1000000000;
		nb = -nb;
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}
