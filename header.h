/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:10:41 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/03 16:10:43 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# define FLAGS "pqrs"
# define STDIN 0

typedef struct	s_glob
{
	unsigned	digest[8];
	char		*alg;
	unsigned	a;
	unsigned	b;
	unsigned	c;
	unsigned	d;
	unsigned	e;
	unsigned	f;
	unsigned	g;
	unsigned	h;
	_Bool		p;
	_Bool		q;
	_Bool		r;
	_Bool		s;
}				t_glob;

t_glob			*glob_data(void);
void			ft_sha256(char *str, _Bool file);
void			ft_sha224(char *str, _Bool file);
void			ft_md5(char *str, _Bool file);
int				find_command(void);
void			parse_args(char **av);
char			**print_sum_str(char **av);
void			read_stdin(void);
void			md5_hashing(unsigned *msg);
void			sha_hashing(unsigned *msg);
void			print_result(unsigned char *hash, char *str, \
	char *alg, _Bool file);
unsigned		*reverse_block(char *block, unsigned long len);
int				print_error(char *alg, char *file);

#endif
