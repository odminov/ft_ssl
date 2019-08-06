/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:20:25 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/11 23:05:29 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		j;

	if (!dst && !src)
		return (NULL);
	i = 0;
	j = len;
	if (src >= dst)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while ((--j) >= 0)
			((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
	}
	return (dst);
}
