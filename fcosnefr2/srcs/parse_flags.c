/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:56:11 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:57:27 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

static int		count_flags(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_flag(str[i]))
		i++;
	return (i);
}

int				parse_flags(char *str, t_format *format, int fnum)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (!(count = count_flags(str + ++i)))
	{
		format[fnum].flags = ft_strnew(0);
		return (i);
	}
	format[fnum].flags = ft_strnew(count);
	while (str[i] && is_flag(str[i]))
		format[fnum].flags[j++] = str[i++];
	return (i);
}
