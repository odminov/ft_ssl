/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:20:00 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/06 19:24:08 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*res;

	i = 0;
	j = 0;
	k = 0;
	res = NULL;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[k])
	{
		if (haystack[i] == needle[j])
		{
			res = &((char *)haystack)[i];
			while (haystack[i++] == needle[j++])
				if (needle[j] == '\0')
					return (res);
			res = NULL;
			j = 0;
		}
		i = ++k;
	}
	return (res);
}
