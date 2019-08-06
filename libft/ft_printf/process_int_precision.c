/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:04:04 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/03 13:56:46 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		zero_flag(t_print *list, char **temp, char **out, char *prefix)
{
	list->add = (int)ft_strlen(prefix);
	*temp = proc_width(list, *out, (int)ft_strlen(*out), '0');
	free(*out);
	*out = ft_strjoin(prefix, *temp);
	free(*temp);
}

static char		*int_without_precision(t_print *list, char *out, char *prefix)
{
	char	*temp;

	if (list->width > (int)ft_strlen(out) + list->add)
	{
		if (list->zero)
		{
			zero_flag(list, &temp, &out, prefix);
			return (out);
		}
		temp = out;
		out = ft_strjoin(prefix, out);
		free(temp);
		temp = out;
		if ((int)ft_strlen(out) < list->width)
		{
			out = proc_width(list, out, (int)ft_strlen(out), ' ');
			free(temp);
		}
		return (out);
	}
	temp = out;
	out = ft_strjoin(prefix, out);
	free(temp);
	return (out);
}

static void		more_len(t_print *list, char **temp, char *prefix, char *out)
{
	int i;

	*temp = prefix;
	while (*prefix)
		++prefix;
	i = list->precision - ft_strlen(out);
	while (i-- > 0)
		*prefix++ = '0';
	prefix = *temp;
}

char			*process_int_precision(t_print *list, char *out, char *prefix)
{
	char	*temp;

	if (list->set_precision)
	{
		if (list->precision > (int)ft_strlen(out))
			more_len(list, &temp, prefix, out);
		temp = out;
		if (!(out = ft_strjoin(prefix, out)))
			return (NULL);
		free(temp);
		if (list->width > (int)ft_strlen(out))
		{
			temp = out;
			out = proc_width(list, out, (int)ft_strlen(out), ' ');
			free(temp);
		}
		return (out);
	}
	return (int_without_precision(list, out, prefix));
}
