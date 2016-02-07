/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:56:02 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:56:03 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

static const t_conv	g_conv[] =
{
	{'s', &flag_s},
	{'S', &flag_s},
	{'p', &flag_p},
	{'d', &flag_d},
	{'D', &flag_d},
	{'i', &flag_d},
	{'o', &flag_o},
	{'O', &flag_o},
	{'u', &flag_u},
	{'U', &flag_u},
	{'x', &flag_x},
	{'X', &flag_x},
	{'c', &flag_c},
	{'C', &flag_c},
	{'%', &flag_percent},
	{'\0', &flag_null}
};

int		parse_conversion(char *str, t_format *format, int fnum)
{
	int i;

	i = 0;
	if (!ft_strequ(format[fnum].modifier, "error"))
	{
		while (g_conv[i].label)
		{
			if (g_conv[i].label == *str)
			{
				format[fnum].conversion = g_conv[i];
				if (g_conv[i].label == '%')
					return (1);
				return (0);
			}
			i++;
		}
	}
	format[fnum].conversion.label = *str;
	format[fnum].conversion.f = &flag_null;
	return (0);
}
