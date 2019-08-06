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

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c ft_lstadd_end.c ft_lstlen.c ft_strcap.c ft_itoa_long.c get_next_line.c ft_iswhite_sp.c

D_OBJ = obj/

OBJ = $(addprefix $(D_OBJ), $(SRC:.c=.o))

NAME = libft.a
INC = libft.h

all: $(NAME)


$(D_OBJ)%.o:%.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(D_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ)
	@printf "\x1b[32m%s compiled\n\x1b[0m\n" $(NAME)
	@make -C ./ft_printf

$(D_OBJ):
	mkdir $@

clean:
	@make -C ./ft_printf $@
	rm -rf $(D_OBJ)

fclean: clean
	@make -C ./ft_printf $@
	rm -rf $(NAME)
	rm -rf *~
	rm -rf \#*\#
re: fclean all