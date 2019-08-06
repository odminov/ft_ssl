/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 01:25:49 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 15:47:24 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					contains(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		++i;
	}
	return (0);
}

static int			sizebeforechr(char *str, char c)
{
	int i;

	i = 0;
	while ((str[i]) && (str[i] != c))
	{
		++i;
	}
	return (i);
}

static t_print		*init_list(void)
{
	t_print		*new;

	if (!(new = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	new->align = 0;
	new->sign = 0;
	new->space = 0;
	new->specformat = 0;
	new->zero = 0;
	new->width = 0;
	new->precision = 0;
	new->set_precision = 0;
	new->typemod = '\0';
	new->doublemod = 0;
	new->add = 0;
	new->type = '\0';
	new->out = NULL;
	new->next = NULL;
	return (new);
}

static int			copytolist(char **str, t_print *list)
{
	int i;

	i = 0;
	i = sizebeforechr(*str, '%');
	if (i)
	{
		if (!(list->out = (char *)malloc(i + 1)))
			return (-1);
		ft_strncpy(list->out, *str, i);
		list->out[i] = '\0';
	}
	if (contains(*str, '%'))
	{
		(*str) += i + 1;
		return (1);
	}
	else
		(*str) += i;
	return (0);
}

t_print				*parse_format(char *format)
{
	t_print		*new;
	t_print		*head;
	int			res;

	new = init_list();
	head = new;
	while (*format)
	{
		if ((res = copytolist(&format, new)) == -1)
			return (NULL);
		if (res)
		{
			new->next = init_list();
			new = new->next;
		}
		if (format && *format)
		{
			parse_percent(&format, new);
			if (!*format)
				break ;
			new->next = init_list();
			new = new->next;
		}
	}
	return (head);
}
