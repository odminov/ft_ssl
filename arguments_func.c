/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:11:16 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/07 21:11:16 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define ALG glob_data()->alg

extern char *g_list_commands[];
extern void (*g_list_func[]) (char *, _Bool);

int		find_command(void)
{
	int	i;

	if (read(0, NULL, 0) < 0)
	{
		ft_printf("./ft_ssl: %s: %s\n", glob_data()->alg, strerror(errno));
		return (0);
	}
	i = 0;
	while (g_list_commands[i])
	{
		if (ft_strcmp(glob_data()->alg, g_list_commands[i]) == 0)
		{
			g_list_func[i](NULL, 0);
			break ;
		}
		i++;
	}
	return (1);
}

char	**print_sum_str(char **av)
{
	int		i;
	char	*str;

	(*av)++;
	if (**av)
		str = *av;
	else if (++av && *av)
		str = *av;
	else
	{
		ft_printf("ft_ssl: %s: option requires an argument -- s\n", ALG);
		ft_printf("usage: ./ft_ssl %s [-pqr] [-s string] [files ...]\n", ALG);
		exit(1);
	}
	i = 0;
	while (g_list_commands[i])
	{
		if (ft_strcmp(glob_data()->alg, g_list_commands[i]) == 0)
		{
			g_list_func[i](str, 0);
			break ;
		}
		i++;
	}
	return (av);
}

void	read_stdin(void)
{
	int i;

	if (read(0, NULL, 0) < 0)
	{
		ft_printf("./ft_ssl: %s: %s\n", glob_data()->alg, strerror(errno));
		return ;
	}
	i = 0;
	while (g_list_commands[i])
	{
		if (ft_strcmp(glob_data()->alg, g_list_commands[i]) == 0)
		{
			g_list_func[i](NULL, 0);
			break ;
		}
		i++;
	}
}
