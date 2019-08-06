/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:14:10 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/07 21:14:11 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern char	*g_list_commands[];
extern void	(*g_list_func[]) (char *, _Bool);

static int	contains(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static void	write_flag(char c)
{
	t_glob *flags;

	flags = glob_data();
	if (c == 'q')
		flags->q = 1;
	else if (c == 'p')
		flags->p = 1;
	else if (c == 'r')
		flags->r = 1;
	else if (c == 's')
		flags->s = 1;
}

static char	**parse_flags(char **av)
{
	while (*av && **av)
	{
		if (**av == 's' && (glob_data()->s = 1))
		{
			av = print_sum_str(av);
			return (av);
		}
		else if (**av == 'p')
		{
			if (glob_data()->p == 0 && (glob_data()->p = 1))
				read_stdin();
		}
		else if (contains(FLAGS, **av))
			write_flag(**av);
		else
		{
			ft_printf("ft_ssl: md5: illegal option -- %c\n", **av);
			ft_printf("usage: ./ft_ssl md5 [-pqr] [-s string] [files ...]\n");
			exit(1);
		}
		if (*av)
			(*av)++;
	}
	return (av);
}

static void	parse_files(char **av)
{
	t_glob	*flags;
	int		i;

	flags = glob_data();
	i = 0;
	while (g_list_commands[i])
	{
		if (ft_strcmp(glob_data()->alg, g_list_commands[i]) == 0)
		{
			while (av && *av)
			{
				g_list_func[i](*av, 1);
				av++;
			}
			break ;
		}
		i++;
	}
}

void		parse_args(char **av)
{
	if (!*av)
	{
		if (!find_command())
			return ;
	}
	else
	{
		while (*av)
		{
			if (**av != '-')
				break ;
			(*av)++;
			if (*av && !**av)
			{
				(*av)--;
				break ;
			}
			av = parse_flags(av);
			if (av && *av)
				av++;
		}
		(glob_data()->s || glob_data()->p || (*av)) ? 0 : read_stdin();
		parse_files(av);
	}
}
