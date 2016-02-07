/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:03:51 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:33:20 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*add_sign(t_format *f, long long int nb)
{
	if (nb < 0)
		f->out = add_string(f, 1, '-', 1);
	else
	{
		if (ft_strchr(f->flags, '+'))
		{
			if (nb >= 0)
				f->out = add_string(f, 1, '+', 1);
		}
		else
		{
			if (ft_strchr(f->flags, ' '))
				if (nb >= 0)
					f->out = add_string(f, 1, ' ', 1);
		}
	}
	return (f->out);
}

static void			get_ou(t_format *f, va_list *ap, long long int *nb, char *c)
{
	*c = (ft_strchr(f->flags, '0') ? '0' : ' ');
	*c = (f->precision_set ? ' ' : *c);
	if (f->conversion.label == 'D')
		*nb = (long long int)(va_arg(*ap, long int));
	else
		*nb = get_arg(f->modifier, ap);
	if (f->precision_set && f->precision == 0 && *nb == 0)
		f->out = ft_strdup("");
	else
		f->out = ft_ullitoa(*nb < 0 ? -(*nb) : *nb);
	f->to_free = 1;
	if (f->precision_set)
		f->out = add_string(f, f->precision - ft_strlen(f->out), '0', 1);
}

int					flag_d(t_format f, va_list *ap)
{
	long long int	nb;
	int				len;
	char			c;
	int				left;

	get_ou(&f, ap, &nb, &c);
	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	len = 0;
	if ((left ? c : ' ') != '0')
		f.out = add_sign(&f, nb);
	else
	{
		if ((nb < 0) || (nb >= 0 && (ft_strchr(f.flags, '+') ||
							ft_strchr(f.flags, ' '))))
			len--;
	}
	len += f.length - ft_strlen(f.out);
	f.out = add_string(&f, len, (left ? c : ' '), left);
	if ((left ? c : ' ') == '0')
		f.out = add_sign(&f, nb);
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	if (f.to_free)
		free(f.out);
	return (len);
}
