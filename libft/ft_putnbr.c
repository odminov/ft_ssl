/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:29:43 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/10 01:03:39 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digit(int n)
{
	unsigned int i;

	i = 1;
	if (n < -9)
	{
		n = (n / 10) * (-1);
		i = 10;
	}
	while (n > 9)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

void			ft_putnbr(int n)
{
	int mul;

	mul = count_digit(n);
	if (n < 0)
	{
		ft_putchar('-');
		ft_putchar((n / mul) * (-1) + '0');
		n = (n % mul) * (-1);
		mul /= 10;
	}
	while (n > 0 || mul >= 1)
	{
		if (n == 0)
			ft_putchar('0');
		else
		{
			ft_putchar((n / mul) + '0');
			n = n % mul;
		}
		mul /= 10;
	}
}
