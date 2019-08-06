/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:42:42 by ahonchar          #+#    #+#             */
/*   Updated: 2017/11/21 15:36:39 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == c)
			res = &((char *)s)[i];
		i++;
	}
	if (s[i] == c)
		res = &((char *)s)[i];
	return (res);
}
