/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:39:33 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/21 23:39:34 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_H
# define SHA_H

# define A regs->digest[0]
# define B regs->digest[1]
# define C regs->digest[2]
# define D regs->digest[3]
# define E regs->digest[4]
# define F regs->digest[5]
# define G regs->digest[6]
# define H regs->digest[7]

# define ROTR(x, n) (((unsigned)(x) >> (n)) | ((x) << (32-(n))))

# define SHA_BUFSIZE 64 * sizeof(unsigned)

#endif
