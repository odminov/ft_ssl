/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:16:36 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 16:45:45 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	to_hex(int value, _Bool upper)
{
	int add;

	if (upper)
		add = 55;
	else
		add = 87;
	if (value < 10)
		return (value + '0');
	return (value + add);
}

void	convert(unsigned long value, unsigned long base, char **out, _Bool upp)
{
	if (value >= base)
	{
		convert(value / base, base, out, upp);
		++(*out);
		**out = to_hex(value % base, upp);
	}
	else
	{
		**out = to_hex(value, upp);
	}
}

char	*ft_itoa_base(unsigned long value, int base, _Bool upper)
{
	char	*out;
	char	*begin;

	out = (char *)malloc(65);
	begin = out;
	out[64] = '\0';
	convert(value, (unsigned long)base, &out, upper);
	++out;
	*out = '\0';
	return (begin);
}
