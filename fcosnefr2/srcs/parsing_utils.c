/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:56:58 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:56:59 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

int		is_conversion(char c)
{
	int		i;
	char	*format;

	i = 0;
	format = "sSpdDioOuUxXcC%";
	while (format[i])
	{
		if (format[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_flag(char c)

{
	int		i;
	char	*flags;

	i = 0;
	flags = "#0-+ ";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_modifier(char *str)
{
	if (str[0] == 'h' && str[1] == 'h')
		return (1);
	if (str[0] == 'h')
		return (1);
	if (str[0] == 'l' && str[1] == 'l')
		return (1);
	if (str[0] == 'l')
		return (1);
	if (str[0] == 'j')
		return (1);
	if (str[0] == 'z')
		return (1);
	return (0);
}

int		is_allowed(char *str)
{
	if (is_flag(str[0]) || is_conversion(str[0]) ||
			is_modifier(str) || (str[0] >= '0' && str[0] <= '9') ||
			str[0] == '.')
		return (1);
	return (0);
}
