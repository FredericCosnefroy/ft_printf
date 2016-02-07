/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:23:15 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 12:37:54 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char							*convert_to_octal(unsigned long long int nb)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(32);
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[i] = (nb % 8) + '0';
		i++;
		nb /= 8;
	}
	return (invert_chars(str));
}

static unsigned long long int	get_nb(t_format f, va_list *ap)
{
	if (f.conversion.label == 'O')
		return ((unsigned long long int)(va_arg(*ap, unsigned long int)));
	else
		return (get_unsigned_arg(f.modifier, ap));
}

int								flag_o(t_format f, va_list *ap)
{
	unsigned long long int	nb;
	char					c;
	int						left;
	int						len;

	nb = get_nb(f, ap);
	if (nb == 0 && f.precision_set && f.precision == 0
			&& !ft_strchr(f.flags, '#'))
		f.out = ft_strdup("");
	else
		f.out = convert_to_octal(nb);
	f.to_free = 1;
	if (ft_strchr(f.flags, '#') && nb != 0)
		f.out = add_string(&f, 1, '0', 1);
	if (f.precision_set)
		f.out = add_string(&f, f.precision - ft_strlen(f.out), '0', 1);
	c = (ft_strchr(f.flags, '0') ? '0' : ' ');
	c = (f.precision_set ? ' ' : c);
	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	f.out = add_string(&f, f.length - ft_strlen(f.out), (left ? c : ' '), left);
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	free(f.out);
	return (len);
}
