/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_minus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:24:10 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/03 14:24:22 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		delete_minus(char **src)
{
	char	*new;
	char	*temp;
	int		i;

	temp = *src;
	new = (char *)malloc(ft_strlen(*src));
	i = 0;
	while (**src)
	{
		if (**src == '-')
		{
			++(*src);
			continue;
		}
		new[i++] = **src;
		++(*src);
	}
	new[i] = '\0';
	free(temp);
	*src = new;
}
