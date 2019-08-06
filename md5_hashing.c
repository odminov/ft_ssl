/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hashing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:05:27 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/19 18:05:29 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "md5.h"

#define A regs->digest[0]
#define B regs->digest[1]
#define C regs->digest[2]
#define D regs->digest[3]

static void	step_1(unsigned *x)
{
	t_glob	*regs;

	regs = glob_data();
	FF(A, B, C, D, x[0], S11, 0xd76aa478);
	FF(D, A, B, C, x[1], S12, 0xe8c7b756);
	FF(C, D, A, B, x[2], S13, 0x242070db);
	FF(B, C, D, A, x[3], S14, 0xc1bdceee);
	FF(A, B, C, D, x[4], S11, 0xf57c0faf);
	FF(D, A, B, C, x[5], S12, 0x4787c62a);
	FF(C, D, A, B, x[6], S13, 0xa8304613);
	FF(B, C, D, A, x[7], S14, 0xfd469501);
	FF(A, B, C, D, x[8], S11, 0x698098d8);
	FF(D, A, B, C, x[9], S12, 0x8b44f7af);
	FF(C, D, A, B, x[10], S13, 0xffff5bb1);
	FF(B, C, D, A, x[11], S14, 0x895cd7be);
	FF(A, B, C, D, x[12], S11, 0x6b901122);
	FF(D, A, B, C, x[13], S12, 0xfd987193);
	FF(C, D, A, B, x[14], S13, 0xa679438e);
	FF(B, C, D, A, x[15], S14, 0x49b40821);
}

static void	step_2(unsigned *x)
{
	t_glob	*regs;

	regs = glob_data();
	GG(A, B, C, D, x[1], S21, 0xf61e2562);
	GG(D, A, B, C, x[6], S22, 0xc040b340);
	GG(C, D, A, B, x[11], S23, 0x265e5a51);
	GG(B, C, D, A, x[0], S24, 0xe9b6c7aa);
	GG(A, B, C, D, x[5], S21, 0xd62f105d);
	GG(D, A, B, C, x[10], S22, 0x2441453);
	GG(C, D, A, B, x[15], S23, 0xd8a1e681);
	GG(B, C, D, A, x[4], S24, 0xe7d3fbc8);
	GG(A, B, C, D, x[9], S21, 0x21e1cde6);
	GG(D, A, B, C, x[14], S22, 0xc33707d6);
	GG(C, D, A, B, x[3], S23, 0xf4d50d87);
	GG(B, C, D, A, x[8], S24, 0x455a14ed);
	GG(A, B, C, D, x[13], S21, 0xa9e3e905);
	GG(D, A, B, C, x[2], S22, 0xfcefa3f8);
	GG(C, D, A, B, x[7], S23, 0x676f02d9);
	GG(B, C, D, A, x[12], S24, 0x8d2a4c8a);
}

static void	step_3(unsigned *x)
{
	t_glob	*regs;

	regs = glob_data();
	HH(A, B, C, D, x[5], S31, 0xfffa3942);
	HH(D, A, B, C, x[8], S32, 0x8771f681);
	HH(C, D, A, B, x[11], S33, 0x6d9d6122);
	HH(B, C, D, A, x[14], S34, 0xfde5380c);
	HH(A, B, C, D, x[1], S31, 0xa4beea44);
	HH(D, A, B, C, x[4], S32, 0x4bdecfa9);
	HH(C, D, A, B, x[7], S33, 0xf6bb4b60);
	HH(B, C, D, A, x[10], S34, 0xbebfbc70);
	HH(A, B, C, D, x[13], S31, 0x289b7ec6);
	HH(D, A, B, C, x[0], S32, 0xeaa127fa);
	HH(C, D, A, B, x[3], S33, 0xd4ef3085);
	HH(B, C, D, A, x[6], S34, 0x4881d05);
	HH(A, B, C, D, x[9], S31, 0xd9d4d039);
	HH(D, A, B, C, x[12], S32, 0xe6db99e5);
	HH(C, D, A, B, x[15], S33, 0x1fa27cf8);
	HH(B, C, D, A, x[2], S34, 0xc4ac5665);
}

static void	step_4(unsigned *x)
{
	t_glob	*regs;

	regs = glob_data();
	II(A, B, C, D, x[0], S41, 0xf4292244);
	II(D, A, B, C, x[7], S42, 0x432aff97);
	II(C, D, A, B, x[14], S43, 0xab9423a7);
	II(B, C, D, A, x[5], S44, 0xfc93a039);
	II(A, B, C, D, x[12], S41, 0x655b59c3);
	II(D, A, B, C, x[3], S42, 0x8f0ccc92);
	II(C, D, A, B, x[10], S43, 0xffeff47d);
	II(B, C, D, A, x[1], S44, 0x85845dd1);
	II(A, B, C, D, x[8], S41, 0x6fa87e4f);
	II(D, A, B, C, x[15], S42, 0xfe2ce6e0);
	II(C, D, A, B, x[6], S43, 0xa3014314);
	II(B, C, D, A, x[13], S44, 0x4e0811a1);
	II(A, B, C, D, x[4], S41, 0xf7537e82);
	II(D, A, B, C, x[11], S42, 0xbd3af235);
	II(C, D, A, B, x[2], S43, 0x2ad7d2bb);
	II(B, C, D, A, x[9], S44, 0xeb86d391);
}

void		md5_hashing(unsigned *msg)
{
	t_glob		*regs;
	unsigned	aa;
	unsigned	bb;
	unsigned	cc;
	unsigned	dd;

	regs = glob_data();
	aa = A;
	bb = B;
	cc = C;
	dd = D;
	step_1(msg);
	step_2(msg);
	step_3(msg);
	step_4(msg);
	A += aa;
	B += bb;
	C += cc;
	D += dd;
}
