/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 10:12:08 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/03 18:10:15 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_prefix(t_print *list, char *prefix, int count)
{
	if ((list->type != 'u' && list->type != 'U') && list->sign)
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = '+';
	}
	if (list->type != 'u' && list->type != 'U' && !list->sign && list->space)
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = ' ';
	}
	if (list->type != 'u' && list->type != 'U' && !list->sign && !list->space)
	{
		if (count < 0)
			prefix[0] = '-';
		else
			prefix[0] = '\0';
	}
}

int		check_type1(t_print *list, va_list arg, char **out, signed long *s_num)
{
	int i;

	i = 1;
	if (((list->type == 'd' || list->type == 'i') && (list->typemod == 'l'
		|| list->typemod == 'j' || list->typemod == 'z')) || list->type == 'D')
	{
		*s_num = va_arg(arg, signed long);
		*out = ft_itoa_long(s_num, 's');
	}
	else if ((list->type == 'd' || list->type == 'i') &&
		(list->typemod == 'h' && !list->doublemod))
	{
		*s_num = (short)va_arg(arg, signed long);
		*out = ft_itoa_long(s_num, 's');
	}
	else if ((list->type == 'd' || list->type == 'i') &&
		(list->typemod == 'h' && list->doublemod))
	{
		*s_num = (signed char)va_arg(arg, signed long);
		*out = ft_itoa_long(s_num, 's');
	}
	else
		i = 0;
	return (i);
}

int		check_type2(t_print *list, va_list arg, char **out, signed long *s_num)
{
	int i;

	i = 1;
	if ((list->type == 'u') && (list->typemod == 'h' && !list->doublemod))
	{
		*s_num = (unsigned short)va_arg(arg, unsigned long);
		*out = ft_itoa_long(s_num, 's');
	}
	else if (list->type == 'u' && list->typemod == 'h' && list->doublemod)
	{
		*s_num = (unsigned char)va_arg(arg, signed long);
		*out = ft_itoa_long(s_num, 's');
	}
	else
	{
		*s_num = va_arg(arg, int);
		*out = ft_itoa_long(s_num, 's');
	}
	return (i);
}

int		check_type(t_print *list, va_list arg, char **out)
{
	unsigned long	u_num;
	signed long		s_num;

	s_num = 0;
	if (!check_type1(list, arg, out, &s_num))
	{
		if ((list->type == 'u' && (list->typemod == 'l'
	|| list->typemod == 'j' || list->typemod == 'z')) || list->type == 'U')
		{
			u_num = va_arg(arg, unsigned long);
			*out = ft_itoa_long(&u_num, 'u');
		}
		else if (list->type == 'u' && list->typemod == '\0')
		{
			u_num = va_arg(arg, unsigned);
			*out = ft_itoa_long(&u_num, 'u');
		}
		else
			check_type2(list, arg, out, &s_num);
	}
	if (s_num < 0)
		delete_minus(out);
	return (s_num < 0 ? -1 : 1);
}

int		processing_number(t_print *list, va_list arg)
{
	char	*out;
	char	*prefix;
	int		sign;
	int		pref_size;

	star(list, arg);
	sign = check_type(list, arg, &out);
	if ((list->set_precision) && (!ft_strcmp(out, "0")))
		*out = '\0';
	pref_size = 2;
	if (list->precision - (int)ft_strlen(out) > 0)
		pref_size += list->precision - (int)ft_strlen(out);
	prefix = ft_strnew(pref_size);
	set_prefix(list, prefix, sign);
	if (!(list->out = process_int_precision(list, out, prefix)))
		return (-1);
	free(prefix);
	list->add = 0;
	return (1);
}
