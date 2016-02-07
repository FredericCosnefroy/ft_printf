/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:37:17 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 17:20:59 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_u(t_format f, va_list *ap)
{
	unsigned long long int	nb;
	int						len;
	char					c;
	int						left;

	if (f.conversion.label == 'U')
		nb = (unsigned long long int)(va_arg(*ap, unsigned long int));
	else
		nb = get_unsigned_arg(f.modifier, ap);
	if (f.precision_set && f.precision == 0 && nb == 0)
		f.out = ft_strdup("");
	else
		f.out = ft_ullitoa(nb);
	f.to_free = 1;
	len = ft_strlen(f.out);
	if (f.precision_set)
		f.out = add_string(&f, f.precision - len, '0', 1);
	c = (ft_strchr(f.flags, '0') ? '0' : ' ');
	c = (f.precision_set ? ' ' : c);
	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	f.out = add_string(&f, f.length - ft_strlen(f.out), (left ? c : ' '), left);
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	free(f.out);
	return (len);
}
