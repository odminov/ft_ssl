/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:25:18 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/03 19:31:58 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			check_unicode(t_print *list, va_list arg, char *str)
{
	unsigned	val;

	if (list->type == 'C' || (list->type == 'c' && list->typemod == 'l'))
	{
		if (!(val = va_arg(arg, unsigned)))
		{
			list->width -= 1;
			list->zero = 1;
			return (1);
		}
		if (!parse_unicode(str, val))
		{
			free(str);
			return (-1);
		}
		return (1);
	}
	if (!(str[0] = (char)va_arg(arg, unsigned)))
	{
		list->width -= 1;
		list->zero = 1;
	}
	return (1);
}

int			processing_char(t_print *list, va_list arg)
{
	char		*out;
	char		*str;
	int			len;

	star(list, arg);
	str = ft_strnew(4);
	list->zero = 0;
	if (check_unicode(list, arg, str) < 0)
		return (-1);
	len = ft_strlen(str);
	if ((list->width) && (list->width > len))
	{
		if (!(list->out = proc_width(list, str, len, ' ')))
			return (-1);
	}
	else
	{
		if (!(out = ft_strnew(len)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	free(str);
	return (1);
}

int			processing_percent(t_print *list, va_list arg)
{
	char	*out;
	char	*str;
	int		len;
	char	c;

	star(list, arg);
	c = ' ';
	len = 1;
	str = ft_strnew(1);
	str[0] = '%';
	if (list->zero)
		c = '0';
	if ((list->width) && (list->width > len))
	{
		if (!(list->out = proc_width(list, str, len, c)))
			return (-1);
	}
	else
	{
		if (!(out = (char *)malloc(len + 1)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	free(str);
	return (1);
}
