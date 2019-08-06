/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:07:16 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/07 21:07:17 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define A regs->digest[0]
#define B regs->digest[1]
#define C regs->digest[2]
#define D regs->digest[3]

static void	add_block(char *str, unsigned curr_len, unsigned long total_len)
{
	unsigned long	*size;
	char			new_block[64];

	ft_bzero(new_block, 64);
	if (curr_len < 64)
	{
		str[curr_len] = 0x80;
	}
	else
		*new_block = 0x80;
	if (curr_len < 56)
	{
		size = (unsigned long *)(((unsigned *)str) + 14);
		*size = total_len * 8;
		md5_hashing((unsigned *)str);
		return ;
	}
	size = (unsigned long *)(((unsigned *)new_block) + 14);
	*size = total_len * 8;
	md5_hashing((unsigned *)str);
	md5_hashing((unsigned *)new_block);
}

static void	read_fd(int fd, char *str, _Bool file)
{
	int				ret;
	unsigned long	len;
	char			buf[64];
	t_glob			*regs;

	regs = glob_data();
	len = 0;
	ft_bzero(buf, 64);
	while ((ret = read(fd, buf, 64)) == 64)
	{
		md5_hashing((unsigned *)buf);
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
		print_error("md5:", str);
	if (ret >= 0)
		print_result((unsigned char *)regs->digest, str, "MD5", file);
}

static void	read_str(char *str)
{
	int			len;
	char		buf[64];
	char		*def_str;

	def_str = str;
	len = ft_strlen(str);
	while (ft_strlen(str) > 64)
	{
		ft_strncpy(buf, str, 64);
		md5_hashing((unsigned *)buf);
		str += 64;
	}
	ft_strncpy(buf, str, 64);
	add_block(buf, ft_strlen(str), len);
	print_result((unsigned char *)glob_data()->digest, def_str, "MD5", 0);
}

void		ft_md5(char *str, _Bool file)
{
	int			fd;
	t_glob		*regs;

	regs = glob_data();
	A = 0x67452301;
	B = 0xefcdab89;
	C = 0x98badcfe;
	D = 0x10325476;
	if (str && !file)
		read_str(str);
	else if (!str && !file)
		read_fd(STDIN, str, file);
	else if (str && file)
	{
		if ((fd = open(str, O_RDONLY)) < 0)
			print_error("md5:", str);
		else
			read_fd(fd, str, file);
		if (fd > 0)
			close(fd);
	}
}
