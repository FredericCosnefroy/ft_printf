/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:42:37 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 16:33:41 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct			s_conv
{
	char				label;
	int					(*f)();
}						t_conv;

typedef struct			s_format
{
	char				*flags;
	int					length;
	int					precision;
	char				*modifier;
	t_conv				conversion;
	int					precision_set;
	int					to_free;
	char				*out;
}						t_format;

typedef struct			s_main
{
	t_format			*format;
	int					size;
}						t_main;

int						ft_printf(char *str, ...);

int						skip_format(char *str);
int						count_format(char *str);
int						format_index(char *str);

int						intlen(int nb);
char					*invert_chars(char *str);
char					*add_string(t_format *f, int len, char c, int left);

int						parse_conversion(char *str, t_format *format, int fnum);
int						parse_flags(char *str, t_format *format, int fnum);
int						parse_length(char *str, t_format *format, int fnum);
int						parse_modifier(char *str, t_format *format, int fnum);
int						parse_precision(char *str, t_format *format, int fnum);

int						is_conversion(char c);
int						is_flag(char c);
int						is_modifier(char *str);
int						is_allowed(char *str);

int						flag_s(t_format f, va_list *ap);
int						flag_p(t_format f, va_list *ap);
int						flag_d(t_format f, va_list *ap);
int						flag_o(t_format f, va_list *ap);
int						flag_x(t_format f, va_list *ap);
int						flag_u(t_format f, va_list *ap);
int						flag_c(t_format f, va_list *ap);
int						flag_percent(t_format f, va_list *ap);
int						flag_null(t_format f, va_list *ap);

unsigned int			ft_wstrlen(wchar_t *wstr);
int						ft_wstrconv(char *buff, wchar_t *wstr);
int						ft_wstrnconv(char *buff, wchar_t *wstr, int n);
int						ft_widetoa(char *buff, wchar_t w);

long long int			get_arg(char *mod, va_list *ap);
unsigned long long int	get_unsigned_arg(char *mod, va_list *ap);

#endif
