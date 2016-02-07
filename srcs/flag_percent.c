/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:11:54 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 14:39:43 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_percent(t_format f, va_list *ap)
{
	char	c;
	char	ch;
	int		left;
	int		len;

	ch = '%';
	f.out = ft_strnew(1);
	f.out[0] = ch;
	f.out[1] = '\0';
	f.to_free = 1;
	c = (ft_strchr(f.flags, '0') ? '0' : ' ');
	left = (ft_strchr(f.flags, '-') ? 0 : 1);
	f.out = add_string(&f, f.length - ft_strlen(f.out), (left ? c : ' '), left);
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	free(f.out);
	(void)*ap;
	return (len);
}
