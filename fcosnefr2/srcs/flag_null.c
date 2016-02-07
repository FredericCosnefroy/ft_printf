/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 19:12:44 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 12:36:30 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_null(t_format f, va_list *ap)
{
	int c;
	int left;
	int len;

	(void)(*ap);
	f.to_free = 1;
	f.out = ft_strnew(1);
	f.out[0] = f.conversion.label;
	c = (ft_strchr(f.flags, '0') ? '0' : ' ');
	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	f.out = add_string(&f, f.length - ft_strlen(f.out), (left ? c : ' '), left);
	len = ft_strlen(f.out);
	write(1, f.out, len);
	free(f.out);
	(void)(*ap);
	return (len);
}
