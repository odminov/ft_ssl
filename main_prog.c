/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:34:39 by ahonchar          #+#    #+#             */
/*   Updated: 2018/11/26 19:37:32 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int					main(void)
{
	int i;
	int fd;

	i = 0;
	fd = open("lol", O_RDWR);
	while (i <= 100)
	{
		write(fd, "\0", 1);
		i++;
	}
	return (0);
}
