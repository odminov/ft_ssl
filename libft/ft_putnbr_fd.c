/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:28:43 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/10 01:04:33 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digit_fd(int n)
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

void			ft_putnbr_fd(int n, int fd)
{
	int mul;

	mul = count_digit_fd(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((n / mul) * (-1) + '0', fd);
		n = (n % mul) * (-1);
		mul /= 10;
	}
	while (n > 0 || mul >= 1)
	{
		if (n == 0)
			ft_putchar_fd('0', fd);
		else
		{
			ft_putchar_fd((n / mul) + '0', fd);
			n = n % mul;
		}
		mul /= 10;
	}
}
