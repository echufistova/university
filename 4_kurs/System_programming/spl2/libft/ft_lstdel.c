/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:04:38 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/08 14:12:33 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *dop;

	if (alst && *alst && del)
	{
		while ((*alst))
		{
			dop = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = dop;
		}
	}
}
