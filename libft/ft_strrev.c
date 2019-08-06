/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:49:13 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/02 20:46:00 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrev(char *str)
{
	char	c;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (str);
	i--;
	j = i;
	while (i > 0)
	{
		c = str[j - i];
		str[j - i] = str[i];
		str[i] = c;
		i--;
		if (j / 2 == i)
			return (str);
	}
	return (str);
}
