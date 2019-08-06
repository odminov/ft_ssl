/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:04:04 by ahonchar          #+#    #+#             */
/*   Updated: 2018/03/29 20:28:44 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*unsi_ll(unsigned long long *num, char **out)
{
	int i;

	i = 0;
	if (!num)
		return (NULL);
	while (*num > 9)
	{
		(*out)[i++] = *num % 10 + '0';
		*num = *num / 10;
	}
	(*out)[i++] = *num + '0';
	(*out)[i] = '\0';
	(*out) = ft_strrev(*out);
	return (*out);
}

static char	*sign_ll(signed long long *num, char **out)
{
	int i;
	int sign;

	i = 0;
	if (!num)
		return (NULL);
	sign = 1;
	if (*num < 0)
		sign = -1;
	while (*num > 9 || *num < -9)
	{
		(*out)[i++] = (*num % 10 * sign) + '0';
		*num = *num / 10;
	}
	(*out)[i++] = (*num * sign) + '0';
	if (sign == -1)
		(*out)[i++] = '-';
	(*out)[i] = '\0';
	(*out) = ft_strrev(*out);
	return (*out);
}

char		*ft_itoa_long(void *num, char type)
{
	unsigned long long	u_num;
	signed long long	s_num;
	int					len;
	char				*out;

	len = 1;
	if (type == 'u')
	{
		u_num = *((unsigned long long *)num);
		while (u_num > 9)
		{
			++len;
			u_num = u_num / 10;
		}
		out = (char *)malloc(sizeof(char *) * len + 1);
		return (unsi_ll((unsigned long long *)num, &out));
	}
	s_num = *((signed long long *)num);
	while (s_num > 9 || s_num < -9)
	{
		++len;
		s_num = s_num / 10;
	}
	out = (char *)malloc(sizeof(char *) * len + 1);
	return (sign_ll((signed long long *)num, &out));
}
