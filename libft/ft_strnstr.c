/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:00:02 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/11 13:24:57 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while (haystack[k] && k < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i++] == needle[j++])
				if (needle[j] == '\0' && i <= len)
					return (&((char *)haystack)[i - j]);
			j = 0;
		}
		else
			i = ++k;
	}
	return (NULL);
}
