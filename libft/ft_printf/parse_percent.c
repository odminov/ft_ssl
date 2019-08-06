/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 01:23:24 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 15:50:00 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		parse_flags(t_print *list, char **str)
{
	if (**str == '#' && ++(*str))
	{
		list->specformat = 1;
	}
	else if (**str == '0' && ++(*str))
	{
		list->zero = 1;
	}
	else if (**str == '-' && ++(*str))
	{
		list->align = 1;
	}
	else if (**str == '+' && ++(*str))
	{
		list->sign = 1;
	}
	else if (**str == ' ' && ++(*str))
	{
		list->space = 1;
	}
	else
		return ;
}

static void		parse_mods(t_print *list, char **str)
{
	list->typemod = **str;
	++(*str);
	if ((**str == 'h') || (**str == 'l'))
	{
		list->doublemod = 1;
		++(*str);
	}
}

static void		parse_width(t_print *list, char **str)
{
	int		i;
	char	width[11];

	i = 0;
	while (**str && ft_isdigit(**str))
	{
		width[i] = **str;
		++i;
		++(*str);
	}
	width[i] = '\0';
	if (**str == '*' && ++(*str))
	{
		list->width = -1;
	}
	else
		list->width = ft_atoi(width);
}

static void		parse_pecision(t_print *list, char **str)
{
	char	precision[11];
	int		i;

	list->set_precision = 1;
	++(*str);
	i = 0;
	while ((**str) && (**str == '0'))
		++(*str);
	while (**str && ft_isdigit(**str))
	{
		precision[i] = **str;
		++i;
		++(*str);
	}
	precision[i] = '\0';
	if (**str == '*' && ++(*str))
	{
		list->precision = -1;
	}
	else
		list->precision = ft_atoi(precision);
}

void			parse_percent(char **str, t_print *list)
{
	while (**str && (!contains(TYPES, **str)))
	{
		if (contains(FLAGS, **str))
			parse_flags(list, str);
		else if (contains(MODS, **str))
			parse_mods(list, str);
		else if (ft_isdigit(**str) || **str == '*')
			parse_width(list, str);
		else if (**str == '.')
			parse_pecision(list, str);
		else
			++(*str);
	}
	list->type = **str;
	if (**str)
		++(*str);
}
