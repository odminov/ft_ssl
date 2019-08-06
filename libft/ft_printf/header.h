/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:35:49 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/08 12:20:40 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define TYPES	"sSpdDioOuUxXcC%"
# define FLAGS	"#0-+ "
# define MODS	"hljz"
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include "../libft.h"

typedef struct		s_print
{
	struct s_print	*next;
	char			*out;
	int				width;
	int				precision;
	char			typemod;
	char			add;
	char			type;
	_Bool			align;
	_Bool			sign;
	_Bool			space;
	_Bool			specformat;
	_Bool			zero;
	_Bool			set_precision;
	_Bool			doublemod;
}					t_print;

int					my_ret(t_print *list, int ret);
void				parse_percent(char **str, t_print *list);
int					parse_unicode(char *str, unsigned value);
int					contains(char *str, char c);
void				delete_minus(char **src);
t_print				*parse_format(char *format);
int					valid(char *format);
int					processing_string(t_print *list, va_list arg);
int					processing_percent(t_print *list, va_list arg);
int					processing_number(t_print *list, va_list arg);
int					processing_char(t_print *list, va_list arg);
char				*proc_width(t_print *list, char *src, int len, char c);
char				*ft_itoa_base(unsigned long value, int base, _Bool upper);
char				*process_int_precision(t_print *list,
						char *out, char *prefix);
int					processing_hex(t_print *list, va_list arg);
int					processing_oct(t_print *list, va_list arg);
int					processing_ptr(t_print *list, va_list arg);
void				star(t_print *list, va_list arg);

#endif
