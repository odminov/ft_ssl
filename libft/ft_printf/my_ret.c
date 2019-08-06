/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:35:49 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/01 16:37:30 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			my_ret(t_print *list, int ret)
{
	while (list)
	{
		if (list->out)
			free(list->out);
		free(list);
		list = list->next;
	}
	return (ret);
}
