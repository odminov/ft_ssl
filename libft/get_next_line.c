/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:24:14 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/05 14:24:16 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		read_from_buff(t_gnl *list, char **line)
{
	char	*nl;
	char	*temp;

	temp = *line;
	if (!(nl = ft_strchr(list->buff, '\n')))
	{
		if (!(*line = ft_strjoin(*line, list->buff)))
			return (-1);
		free(temp);
		return (0);
	}
	*nl = '\0';
	nl++;
	if (!(*line = ft_strjoin(*line, list->buff)))
		return (-1);
	free(temp);
	if (!(temp = ft_strnew(ft_strlen(nl))))
		return (-1);
	ft_strcpy(temp, nl);
	ft_strncpy(list->buff, temp, BUFF_SIZE);
	free(temp);
	return (1);
}

static int		read_line(t_gnl *list, char **line)
{
	int	ret;

	if (!(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if (*list->buff)
		{
			ret = read_from_buff(list, line);
			if (ret)
				return (ret);
			ft_strclr(list->buff);
		}
		if (!(ret = read(list->fd, list->buff, BUFF_SIZE)))
		{
			if (**line)
				return (1);
			else
			{
				free(*line);
				return ((int)(*line = NULL));
			}
		}
		list->buff[ret] = '\0';
	}
}

static t_gnl	*new_list_elem(int fd)
{
	t_gnl	*list;

	if (!(list = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(list->buff = ft_strnew(BUFF_SIZE)))
	{
		free(list);
		return (NULL);
	}
	list->fd = fd;
	list->next = NULL;
	return (list);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*current;

	if (!line || fd < 0 || !BUFF_SIZE || (read(fd, NULL, 0) == -1))
		return (-1);
	if (!head)
	{
		if (!(head = new_list_elem(fd)))
			return (-1);
	}
	current = head;
	while ((current->fd != fd) && current->next)
		current = current->next;
	if ((current->fd) != fd)
	{
		if (!(current->next = new_list_elem(fd)))
			return (-1);
		current = current->next;
	}
	return (read_line(current, line));
}
