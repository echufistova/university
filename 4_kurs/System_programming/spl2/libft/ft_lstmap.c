/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:43:26 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/07 16:53:31 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*res;
	t_list		*res_head;

	res_head = NULL;
	if (lst && f)
	{
		head = lst;
		res = f(lst);
		res_head = res;
		while (lst->next)
		{
			lst = lst->next;
			res->next = f(lst);
			res = res->next;
		}
		lst = head;
		return (res_head);
	}
	return (NULL);
}
