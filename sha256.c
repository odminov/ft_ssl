/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:07:47 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/07 21:07:48 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "sha.h"

static void	add_block(char *str, unsigned curr_len, unsigned long total_len)
{
	char	new_block[64];

	ft_bzero(new_block, 64);
	if (curr_len < 64)
	{
		str[curr_len] = 0x80;
	}
	else
		*new_block = 0x80;
	if (curr_len < 56)
	{
		sha_hashing(reverse_block(str, total_len));
		return ;
	}
	sha_hashing(reverse_block(str, 0));
	sha_hashing(reverse_block(new_block, total_len));
}

static void	read_fd(int fd, char *str, _Bool file)
{
	int				ret;
	unsigned long	len;
	char			buf[SHA_BUFSIZE];
	t_glob			*regs;

	regs = glob_data();
	len = 0;
	ft_bzero(buf, 64);
	while ((ret = read(fd, buf, 64)) == 64)
	{
		sha_hashing(reverse_block(buf, 0));
		if (!str && !file && glob_data()->p)
			ft_printf("%s", buf);
		ft_bzero(buf, 64);
		len += 64;
	}
	if (!str && !file && glob_data()->p)
		ft_printf("%s", buf);
	if (ret >= 0)
		add_block(buf, ret, len + ret);
	else
		print_error("sha256", str);
	if (ret >= 0)
		print_result(NULL, str, "SHA256", file);
}

static void	read_str(char *str)
{
	int			len;
	char		buf[SHA_BUFSIZE];
	t_glob		*regs;
	char		*def_str;

	def_str = str;
	regs = glob_data();
	len = ft_strlen(str);
	while (ft_strlen(str) > 64)
	{
		ft_strncpy(buf, str, 64);
		sha_hashing(reverse_block(buf, 0));
		str += 64;
	}
	ft_strncpy(buf, str, 64);
	add_block(buf, ft_strlen(str), len);
	print_result(NULL, def_str, "SHA256", 0);
}

void		ft_sha256(char *str, _Bool file)
{
	int			fd;
	t_glob		*regs;

	regs = glob_data();
	A = 0x6A09E667;
	B = 0xBB67AE85;
	C = 0x3C6EF372;
	D = 0xA54FF53A;
	E = 0x510E527F;
	F = 0x9B05688C;
	G = 0x1F83D9AB;
	H = 0x5BE0CD19;
	if (str && !file)
		read_str(str);
	else if (!str && !file)
		read_fd(STDIN, str, file);
	else if (str && file)
	{
		if ((fd = open(str, O_RDONLY)) < 0)
			print_error("sha256:", str);
		else
			read_fd(fd, str, file);
		if (fd > 0)
			close(fd);
	}
}
