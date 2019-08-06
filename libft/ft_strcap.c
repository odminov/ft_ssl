/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:50:06 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/16 23:02:59 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcap(char *str)
{
	size_t	i;
	int		upper;

	if (!str)
		return (NULL);
	i = 0;
	upper = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (upper == 0)
			{
				str[i] = ft_toupper(str[i]);
				upper = 1;
			}
			else
				str[i] = ft_tolower(str[i]);
		}
		i++;
	}
	return (str);
}
