/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 16:58:29 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 12:48:01 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			lower_num_letter(int nb)
{
	if (nb == 10)
		return ('a');
	if (nb == 11)
		return ('b');
	if (nb == 12)
		return ('c');
	if (nb == 13)
		return ('d');
	if (nb == 14)
		return ('e');
	if (nb == 15)
		return ('f');
	return (nb + '0');
}

static char			*convert_to_hexa(unsigned long int nb)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(32);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[i] = lower_num_letter(nb % 16);
		i++;
		nb /= 16;
	}
	return (invert_chars(str));
}

static void			get_out(t_format *f, va_list *ap, char *c, int *left)
{
	unsigned long long int	ptr;

	*c = (ft_strchr(f->flags, '0') ? '0' : ' ');
	*c = (f->precision_set ? ' ' : *c);
	*left = (ft_strchr(f->flags, '-') ? 0 : 1);
	ptr = (unsigned long long int)va_arg(*ap, void *);
	if (ptr == 0 && f->precision_set && f->precision == 0)
		f->out = ft_strdup("");
	else
		f->out = convert_to_hexa(ptr);
	f->to_free = 1;
	if (f->precision_set)
		f->out = add_string(f, f->precision - ft_strlen(f->out), '0', 1);
}

int					flag_p(t_format f, va_list *ap)
{
	char					c;
	int						left;
	int						len;

	get_out(&f, ap, &c, &left);
	len = 0;
	if ((left ? c : ' ') != '0')
	{
		f.out = add_string(&f, 1, 'x', 1);
		f.out = add_string(&f, 1, '0', 1);
	}
	else
		len -= 2;
	len += f.length - ft_strlen(f.out);
	f.out = add_string(&f, len, (left ? c : ' '), left);
	if ((left ? c : ' ') == '0')
	{
		f.out = add_string(&f, 1, 'x', 1);
		f.out = add_string(&f, 1, '0', 1);
	}
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	free(f.out);
	return (len);
}
