/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_hashing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:40:58 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/21 23:40:58 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "sha.h"

static const unsigned	g_k[64] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
	0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
	0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
	0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
	0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
	0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
	0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
	0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
	0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

static unsigned	reverse_32(unsigned msg)
{
	return ((msg & 0x000000FFU) << 24 | (msg & 0x0000FF00U) << 8 | \
	(msg & 0x00FF0000U) >> 8 | (msg & 0xFF000000U) >> 24);
}

unsigned		*reverse_block(char *block, unsigned long len)
{
	int			i;
	unsigned	*wrd;

	wrd = (unsigned *)block;
	i = 0;
	while (i < 16)
	{
		wrd[i] = reverse_32(wrd[i]);
		i++;
	}
	if (len)
		*(unsigned long *)(wrd + 15) = len * 8;
	return (wrd);
}

static void		add_message(unsigned *msg)
{
	t_glob		*regs;
	unsigned	s0;
	unsigned	s1;
	int			i;

	regs = glob_data();
	i = 16;
	while (i < 64)
	{
		s0 = (ROTR(msg[i - 15], 7)) ^ (ROTR(msg[i - 15], 18)) \
		^ (msg[i - 15] >> 3);
		s1 = (ROTR(msg[i - 2], 17)) ^ (ROTR(msg[i - 2], 19)) \
		^ (msg[i - 2] >> 10);
		msg[i] = msg[i - 16] + s0 + msg[i - 7] + s1;
		i++;
	}
	regs->a = A;
	regs->b = B;
	regs->c = C;
	regs->d = D;
	regs->e = E;
	regs->f = F;
	regs->g = G;
	regs->h = H;
}

static void		sha_alg(unsigned *msg)
{
	t_glob		*regs;
	unsigned	temp1;
	unsigned	temp2;
	unsigned	ch;
	int			i;

	regs = glob_data();
	i = -1;
	while (++i < 64)
	{
		temp1 = ROTR(regs->a, 2) ^ ROTR(regs->a, 13) ^ ROTR(regs->a, 22);
		temp2 = (regs->a & regs->b) ^ (regs->a & regs->c) ^ (regs->b & regs->c);
		temp2 = temp1 + temp2;
		temp1 = ROTR(regs->e, 6) ^ ROTR(regs->e, 11) ^ ROTR(regs->e, 25);
		ch = (regs->e & regs->f) ^ (~regs->e & regs->g);
		temp1 = regs->h + temp1 + ch + g_k[i] + msg[i];
		regs->h = regs->g;
		regs->g = regs->f;
		regs->f = regs->e;
		regs->e = regs->d + temp1;
		regs->d = regs->c;
		regs->c = regs->b;
		regs->b = regs->a;
		regs->a = temp1 + temp2;
	}
}

void			sha_hashing(unsigned *msg)
{
	t_glob	*regs;

	regs = glob_data();
	add_message(msg);
	sha_alg(msg);
	A += regs->a;
	B += regs->b;
	C += regs->c;
	D += regs->d;
	E += regs->e;
	F += regs->f;
	G += regs->g;
	H += regs->h;
}
