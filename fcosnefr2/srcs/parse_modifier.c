/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:56:33 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:57:57 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

static char	*get_modifier(char *str)
{
	if (str[0] == 'h' && str[1] == 'h')
		return ("hh");
	if (str[0] == 'h')
		return ("h");
	if (str[0] == 'l' && str[1] == 'l')
		return ("ll");
	if (str[0] == 'l')
		return ("l");
	if (str[0] == 'j')
		return ("j");
	if (str[0] == 'z')
		return ("z");
	if (!is_conversion(str[0]))
		return ("error");
	return ("");
}

int			parse_modifier(char *str, t_format *format, int fnum)
{
	char *mod;

	mod = get_modifier(str);
	format[fnum].modifier = mod;
	if (ft_strequ(mod, "error"))
		return (0);
	return (ft_strlen(mod));
}
