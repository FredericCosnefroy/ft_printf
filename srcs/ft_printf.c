/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:19:14 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 16:00:41 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

static t_main	parse_format(char *str)
{
	t_format	*format;
	t_main		mai;
	int			count;
	int			index;
	int			i;

	count = count_format(str);
	format = (t_format *)malloc(sizeof(t_format) * (count));
	index = 0;
	i = 0;
	while (i < count)
	{
		index += parse_flags(str + index, format, i);
		index += parse_length(str + index, format, i);
		index += parse_precision(str + index, format, i);
		index += parse_modifier(str + index, format, i);
		index += parse_conversion(str + index, format, i);
		i++;
	}
	mai.format = format;
	mai.size = count;
	return (mai);
}

int				ft_printf(char *str, ...)
{
	va_list		ap;
	t_main		format;
	int			count;
	int			i;
	int			total;

	i = 0;
	count = 0;
	total = 0;
	format = parse_format(str);
	va_start(ap, str);
	while (i < format.size)
	{
		count = format_index(str);
		total += count;
		write(1, str, count);
		str += count + skip_format(str + count);
		total += format.format[i].conversion.f(format.format[i], &ap);
		free(format.format[i].flags);
		i++;
	}
	write(1, str, ft_strlen(str));
	total += ft_strlen(str);
	va_end(ap);
	return (free(format.format), total);
}
