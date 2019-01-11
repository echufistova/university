/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:50:02 by ychufist          #+#    #+#             */
/*   Updated: 2018/07/16 17:42:56 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		get_line(char ***line, char **stack, char **dop)
{
	unsigned int i;

	i = 0;
	while ((*stack)[i] != '\n' && (*stack)[i] != '\0')
		i++;
	if ((*stack)[i] == '\n')
	{
		**line = ft_strsub(*stack, 0, (size_t)i);
		i++;
		*dop = ft_strsub(*stack, i, strlen(*stack) - i);
		bzero(*stack, strlen(*stack));
		*stack = strdup(*dop);
		bzero(*dop, strlen(*dop));
		return (1);
	}
	return (0);
}

int		check_last(int ret, char **stack_fd, char **line, char **dop)
{
	if (!ret)
	{
		if (*stack_fd && strlen(*stack_fd) != 0)
		{
			if (get_line(&line, stack_fd, dop) == 1)
				return (1);
			*line = strdup(*stack_fd);
			bzero(*stack_fd, strlen(*stack_fd));
			return (1);
		}
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*dop;
	static char		*stack[8192];
	char			buf[BUFF_SIZE + 1];

	if (BUFF_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!stack[fd])
			stack[fd] = strdup(buf);
		else
		{
			dop = ft_strjoin(stack[fd], buf);
			bzero(stack[fd], strlen(stack[fd]));
			stack[fd] = strdup(dop);
			bzero(dop, strlen(dop));
		}
		if (get_line(&line, &stack[fd], &dop) == 1)
			break ;
	}
	return (check_last(ret, &stack[fd], line, &dop));
}
