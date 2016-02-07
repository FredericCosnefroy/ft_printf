/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:56:42 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 16:10:06 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

static void	handle_neg_precision(t_format *f)
{
	char **tmp;

	if (f->precision < 0)
	{
		f->length = -f->precision;
		f->precision = 0;
		f->precision_set = 1;
		tmp = &(f->flags);
		f->flags = ft_strjoin(f->flags, "-");
		free(tmp);
	}
}

static int	handle_zero(char *str, int nb, int i)
{
	if (nb == 0)
	{
		if (str[i] == '0')
		{
			while (str[i] == '0')
				i++;
			return (i);
		}
		else
			return (1);
	}
	else
	{
		while (str[i] == '0')
			i++;
	}
	return (intlen(nb) + i);
}

int			parse_precision(char *str, t_format *format, int fnum)
{
	int i;
	int nb;

	i = 0;
	if (*str == '.')
	{
		format[fnum].precision_set = 1;
		i++;
		nb = ft_atoi(str + i);
		format[fnum].precision = nb;
		handle_neg_precision(&(format[fnum]));
		return (handle_zero(str, nb, i));
	}
	format[fnum].precision = 0;
	format[fnum].precision_set = 0;
	return (0);
}
