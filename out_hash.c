/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:09:32 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/19 18:09:33 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "sha.h"
#include <stdio.h>

#define PR ft_printf

static void	print_md5(unsigned char *hash)
{
	int	i;

	i = 0;
	while (i < 16)
		PR("%.2x", hash[i++]);
}

static void	print_sha(char *alg)
{
	t_glob	*regs;

	regs = glob_data();
	ft_printf("%x%x%x%x%x%x%x", A, B, C, D, E, F, G);
	if (ft_strcmp(alg, "SHA256") == 0)
		ft_printf("%x", H);
}

void		print_result(unsigned char *hash, char *str, char *alg, _Bool file)
{
	t_glob	*flags;

	flags = glob_data();
	if (str)
	{
		if (!flags->q && !flags->r)
		{
			file ? PR("%s (%s) = ", alg, str) : PR("%s (\"%s\") = ", alg, str);
			(!ft_strcmp(alg, "MD5")) ? print_md5(hash) : print_sha(alg);
		}
		else if (!flags->q && flags->r)
		{
			(!ft_strcmp(alg, "MD5")) ? print_md5(hash) : print_sha(alg);
			file ? PR(" %s", str) : PR(" \"%s\"", str);
		}
		else if (flags->q)
			(!ft_strcmp(alg, "MD5")) ? print_md5(hash) : print_sha(alg);
	}
	else
		(!ft_strcmp(alg, "MD5")) ? print_md5(hash) : print_sha(alg);
	PR("\n");
}

int			print_error(char *alg, char *file)
{
	ft_putstr("./ft_ssl: ");
	ft_putstr(alg);
	ft_putstr(" ");
	perror(file);
	return (1);
}
