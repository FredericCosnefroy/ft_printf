/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:54:59 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 14:54:20 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_wc(wchar_t c)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	tmp = ft_strnew(4);
	len = ft_widetoa(tmp, c);
	tmp2 = ft_strsub(tmp, 0, len);
	free(tmp);
	return (tmp2);
}

static void	get_out(t_format *f, va_list *ap)
{
	char	ch;

	if (f->conversion.label == 'C' || ft_strequ(f->modifier, "l"))
		f->out = flag_wc(va_arg(*ap, wchar_t));
	else
	{
		ch = va_arg(*ap, int);
		f->out = ft_strnew(1);
		f->out[0] = ch;
		f->out[1] = '\0';
	}
}

int			flag_c(t_format f, va_list *ap)
{
	char	c;
	int		left;
	int		len;
	int		is_null;

	get_out(&f, ap);
	if (f.out[0] == 0)
		is_null = 1;
	else
		is_null = 0;
	f.to_free = 1;
	c = (ft_strchr(f.flags, '0') ? '0' : ' ');
	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	f.out = add_string(&f, f.length - ft_strlen(f.out) - is_null,
			(left ? c : ' '), left);
	len = ft_strlen(f.out);
	write(1, f.out, len + is_null);
	free(f.out);
	return (len + is_null);
}
