/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:07:27 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/11 13:55:02 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static char	*blank(void)
{
	char	*s;

	s = (char *)malloc(1);
	s[0] = '\0';
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char			*ret;
	unsigned int	i;
	char			*start;
	char			*end;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ret = blank());
	start = &((char *)s)[i];
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	end = &((char *)s)[i];
	ret = (char *)malloc((end - start) + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (start <= end)
		ret[i++] = *start++;
	ret[i] = '\0';
	return (ret);
}
