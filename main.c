/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:51:19 by ahonchar          #+#    #+#             */
/*   Updated: 2018/10/28 17:51:20 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*g_list_commands[] = {
	"md5",
	"sha256",
	"sha224"
	""
};

void (*g_list_func[]) (char *, _Bool) = {
	ft_md5,
	ft_sha256,
	ft_sha224
};

t_glob		*glob_data(void)
{
	static t_glob flags;

	return (&flags);
}

static void	init_globs(t_glob *flags)
{
	flags->alg = NULL;
	flags->q = 0;
	flags->p = 0;
	flags->r = 0;
	flags->s = 0;
}

static void	parse_commands(char **av)
{
	t_glob	*flags;
	int		i;

	flags = glob_data();
	i = 0;
	av++;
	while (*av && g_list_commands[i])
	{
		if (ft_strcmp(*av, g_list_commands[i]) == 0)
		{
			flags->alg = *av;
			av++;
			parse_args(av);
			return ;
		}
		i++;
	}
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", *av);
}

int			main(int ac, char **av)
{
	t_glob *flags;

	if (ac < 2)
	{
		ft_printf("usage: ./ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	flags = glob_data();
	init_globs(flags);
	parse_commands(av);
	return (0);
}
