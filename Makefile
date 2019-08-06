#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahonchar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/10 00:23:32 by ahonchar          #+#    #+#              #
#    Updated: 2018/05/22 18:18:19 by ahonchar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wextra -Wall -Werror

SRC = main.c arguments_func.c parse_args.c md5_hashing.c out_hash.c md5.c sha256.c sha_hashing.c sha224.c

D_OBJ = obj/

OBJ = $(addprefix $(D_OBJ), $(SRC:.c=.o))

NAME = ft_ssl

LIB = ./libft/libft.a ./libft/libftprintf.a

HEADERS = header.h md5.h sha.h

all: libcomile $(NAME)

libcomile:
	@make -C ./libft

$(D_OBJ)%.o:%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@ 

$(NAME): $(D_OBJ) $(OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@printf "\x1b[32m%s compiled\n\x1b[0m\n" $(NAME)

$(D_OBJ):
	mkdir $@

clean:
	@make -C ./libft $@
	rm -rf $(D_OBJ)

fclean: clean
	@make -C ./libft $@
	rm -rf $(NAME)
	rm -rf *~
	rm -rf \#*\#
re: fclean all