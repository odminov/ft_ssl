/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:09:24 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 16:40:16 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char		*proc_width(t_print *list, char *src, int len, char c)
{
	char	*out;
	int		i;

	if (!(out = (char *)malloc(list->width + 1)))
		return (NULL);
	i = list->width - len - (list->add);
	if (!list->align)
	{
		ft_memset(out, c, i);
		while (i < (list->width))
			out[i++] = *src++;
		out[i] = '\0';
		return (out);
	}
	i = 0;
	while (i < (list->width) - (list->add))
	{
		if (i < len)
			out[i] = src[i];
		else
			out[i] = ' ';
		i++;
	}
	out[i] = '\0';
	return (out);
}

int			parse_unicode(char *str, unsigned value)
{
	if (value < 128)
		str[0] = value;
	else if (value > 127 && value < 2048)
	{
		str[0] = value >> 6 | 0xC0;
		str[1] = (value << 26 >> 26) | 0x80;
	}
	else if (value > 2047 && value < 65536)
	{
		str[0] = value >> 12 | 0xE0;
		str[1] = (value << 20 >> 20) >> 6 | 0x80;
		str[2] = (value << 26 >> 26) | 0x80;
	}
	else
	{
		str[0] = value >> 18 | 0xF0;
		str[1] = (value << 14 >> 14) >> 12 | 0x80;
		str[2] = (value << 20 >> 20) >> 6 | 0x80;
		str[3] = (value << 26 >> 26) | 0x80;
	}
	return (1);
}

int			unicode_string(unsigned *str, char **out)
{
	char	*uni_str;
	char	*temp;
	int		i;

	i = 0;
	uni_str = ft_strnew(4);
	*out = ft_strnew(0);
	while (str[i])
	{
		ft_strclr(uni_str);
		if (!parse_unicode(uni_str, str[i]))
		{
			free(uni_str);
			free(*out);
			return (0);
		}
		temp = *out;
		*out = ft_strjoin(*out, uni_str);
		free(temp);
		++i;
	}
	free(uni_str);
	return (1);
}

int			processing_string_p2(t_print *list, int len, char *str)
{
	char		*out;

	if ((list->set_precision) && (list->precision < len))
		len = list->precision;
	if ((list->width) && (list->width > len))
	{
		if (!(list->out = proc_width(list, str, len, ' ')))
			return (-1);
	}
	else
	{
		if (!(out = (char *)malloc(len + 1)))
			return (-1);
		list->out = ft_strncpy(out, str, len);
	}
	if ((list->type == 'S' || (list->type == 's' &&
		list->typemod == 'l')) && ft_strcmp(str, "(null)"))
		free(str);
	return (1);
}

int			processing_string(t_print *list, va_list arg)
{
	char		*str;
	int			len;
	char		err_11[7];
	unsigned	*unicode;

	star(list, arg);
	ft_strcpy(err_11, "(null)");
	if (list->type == 'S' || (list->type == 's' && list->typemod == 'l'))
	{
		if (!(unicode = va_arg(arg, unsigned *)))
			str = NULL;
		else
		{
			if (!unicode_string(unicode, &str))
				return (-1);
		}
	}
	else
		str = va_arg(arg, char *);
	if (!str)
		str = err_11;
	len = (int)ft_strlen(str);
	if ((processing_string_p2(list, len, str)) < 0)
		return (-1);
	return (1);
}
