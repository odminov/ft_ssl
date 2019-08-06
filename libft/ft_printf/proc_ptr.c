/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 22:53:05 by ahonchar          #+#    #+#             */
/*   Updated: 2018/04/27 15:34:38 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	star(t_print *list, va_list arg)
{
	if (list->width == -1)
	{
		if ((list->width = va_arg(arg, int)) < 0)
		{
			list->width = list->width * -1;
			list->align = 1;
		}
	}
	if (list->precision == -1)
	{
		if ((list->precision = va_arg(arg, int)) < 0)
			list->set_precision = 0;
	}
}

int		processing_ptr(t_print *list, va_list arg)
{
	char			*out;
	void			*value;
	char			*prefix;
	int				prefsize;

	star(list, arg);
	value = va_arg(arg, void *);
	out = ft_itoa_base((unsigned long)value, 16, 0);
	prefsize = 2;
	if (list->set_precision)
	{
		if (list->precision - (int)ft_strlen(out) > 0)
			prefsize += list->precision - (int)ft_strlen(out);
	}
	prefix = ft_strnew(prefsize);
	ft_strcpy(prefix, "0x");
	if (!(list->out = process_int_precision(list, out, prefix)))
		return (0);
	free(prefix);
	return (1);
}
