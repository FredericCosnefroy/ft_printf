/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:46:49 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 12:51:56 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			lower_num_letter(int nb, int add)
{
	if (nb == 10)
		return ('a' + add);
	if (nb == 11)
		return ('b' + add);
	if (nb == 12)
		return ('c' + add);
	if (nb == 13)
		return ('d' + add);
	if (nb == 14)
		return ('e' + add);
	if (nb == 15)
		return ('f' + add);
	return (nb + '0');
}

static char			*convert_to_hexa(unsigned long long int nb, t_format format)
{
	char	*str;
	int		add;
	int		i;

	i = 0;
	if (format.conversion.label == 'x')
		add = 0;
	else
		add = -32;
	str = ft_strnew(32);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[i] = lower_num_letter(nb % 16, add);
		i++;
		nb /= 16;
	}
	return (invert_chars(str));
}

char				*add_prefix(t_format *f, unsigned long long int nb)
{
	if (ft_strchr(f->flags, '#') && nb != 0)
	{
		if (f->conversion.label == 'x')
			f->out = add_string(f, 1, 'x', 1);
		else
			f->out = add_string(f, 1, 'X', 1);
		f->out = add_string(f, 1, '0', 1);
	}
	return (f->out);
}

static void			get_out(t_format *f, unsigned long long int nb,
							char *c)
{
	*c = (ft_strchr(f->flags, '0') ? '0' : ' ');
	*c = (f->precision_set ? ' ' : *c);
	if (nb == 0 && f->precision_set && f->precision == 0)
		f->out = ft_strdup("");
	else
		f->out = convert_to_hexa(nb, *f);
	f->to_free = 1;
	if (f->precision_set)
		f->out = add_string(f, f->precision - ft_strlen(f->out), '0', 1);
}

int					flag_x(t_format f, va_list *ap)
{
	unsigned long long int		nb;
	char						c;
	int							left;
	int							len;

	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	nb = get_unsigned_arg(f.modifier, ap);
	get_out(&f, nb, &c);
	len = 0;
	if ((left ? c : ' ') != '0')
		f.out = add_prefix(&f, nb);
	else
	{
		if (ft_strchr(f.flags, '#') && nb != 0)
			len -= 2;
	}
	len += f.length - ft_strlen(f.out);
	f.out = add_string(&f, len, (left ? c : ' '), left);
	if ((left ? c : ' ') == '0')
		f.out = add_prefix(&f, nb);
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	free(f.out);
	return (len);
}
