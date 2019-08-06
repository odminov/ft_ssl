/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:51:35 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/01 13:48:34 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		count_sign(int n)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		sign = -1;
		n /= 10;
		n *= sign;
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	if (sign == -1)
		return (i + 1);
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*str;

	i = count_sign(n);
	sign = 1;
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	if (n < 0)
		sign = -1;
	while (i >= 0)
	{
		if (i == 0 && sign == -1)
			str[i--] = '-';
		else
		{
			str[i--] = (n % 10) * sign + '0';
			n = n / 10;
		}
	}
	return (str);
}
