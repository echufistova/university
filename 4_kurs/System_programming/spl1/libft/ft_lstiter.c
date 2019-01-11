/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:58:57 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/07 15:15:28 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *head;

	head = NULL;
	if (lst && f)
	{
		head = lst;
		while (lst)
		{
			(*f)(lst);
			lst = lst->next;
		}
		lst = head;
	}
}
