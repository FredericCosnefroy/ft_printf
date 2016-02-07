/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getargs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:58:18 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/01/18 18:11:56 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <inttypes.h>
#include <stddef.h>
#include "ft_printf.h"

long long int			get_arg(char *mod, va_list *ap)
{
	if (ft_strequ(mod, "hh"))
		return ((long long int)(signed char)(va_arg(*ap, int)));
	if (ft_strequ(mod, "h"))
		return ((long long int)(short)(va_arg(*ap, int)));
	if (ft_strequ(mod, "ll"))
		return ((long long int)(va_arg(*ap, long long)));
	if (ft_strequ(mod, "l"))
		return ((long long int)(va_arg(*ap, long)));
	if (ft_strequ(mod, "j"))
		return ((long long int)(va_arg(*ap, intmax_t)));
	if (ft_strequ(mod, "z"))
		return ((long long int)(va_arg(*ap, long)));
	return ((long long int)(va_arg(*ap, int)));
}

unsigned long long int	get_unsigned_arg(char *mod, va_list *ap)
{
	if (ft_strequ(mod, "hh"))
		return ((unsigned long long int)(unsigned char)(va_arg(*ap, int)));
	if (ft_strequ(mod, "h"))
		return ((unsigned long long int)(unsigned short)(va_arg(*ap, int)));
	if (ft_strequ(mod, "ll"))
		return ((unsigned long long int)(va_arg(*ap, unsigned long long)));
	if (ft_strequ(mod, "l"))
		return ((unsigned long long int)(va_arg(*ap, unsigned long)));
	if (ft_strequ(mod, "j"))
		return ((unsigned long long int)(va_arg(*ap, uintmax_t)));
	if (ft_strequ(mod, "z"))
		return ((unsigned long long int)(va_arg(*ap, size_t)));
	return ((unsigned long long int)(va_arg(*ap, unsigned int)));
}
