/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:47:55 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/16 22:49:41 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstlen(t_list *alst)
{
	unsigned int	len;

	len = 0;
	while (alst)
	{
		alst = alst->next;
		len++;
	}
	return (len);
}
