/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:56:02 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 16:50:01 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_format_end(char **str)
{
	int		mods;

	mods = 0;
	if (**str == '*')
	{
		if (ft_isdigit(**(str + 1)) && **(str + 1) == '*')
			return (0);
		++(*str);
	}
	while (**str && (contains(MODS, **str)))
	{
		if ((++mods) == 2)
			if (**str != 'l' && **str != 'h')
				return (0);
		if (mods > 2)
			return (0);
		++(*str);
	}
	if (**str && !contains(TYPES, **str))
		return (0);
	++(*str);
	return (1);
}

static int	check_format(char **str)
{
	while (**str && (contains(FLAGS, **str)))
		++(*str);
	while (**str && ft_isdigit(**str))
		++(*str);
	if (**str == '*')
	{
		if (ft_isdigit(**(str + 1)) && **(str + 1) == '*')
			return (0);
		++(*str);
	}
	if (**str == '.' && (++(*str)))
		while (**str && ft_isdigit(**str))
			++(*str);
	if (!check_format_end(str))
		return (0);
	return (1);
}

int			valid(char *format)
{
	char	*ptr;

	while ((ptr = ft_strchr(format, '%')))
	{
		++ptr;
		if (!*ptr)
			return (1);
		if (!check_format(&ptr))
			return (0);
		format = ptr;
	}
	return (1);
}
