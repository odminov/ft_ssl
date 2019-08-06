/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:23:33 by ahonchar          #+#    #+#             */
/*   Updated: 2017/12/06 14:05:47 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*ret;

	ret = NULL;
	if (!lst || !f)
		return (NULL);
	ret = f(lst);
	new_list = ret;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = f(lst);
		if (!new_list->next)
			return (NULL);
		new_list = new_list->next;
	}
	return (ret);
}
