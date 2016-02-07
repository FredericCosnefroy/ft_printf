/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:56:19 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:56:20 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

int		parse_length(char *str, t_format *format, int fnum)
{
	int i;
	int nb;

	nb = ft_atoi(str);
	format[fnum].length = nb;
	i = 0;
	if (nb == 0)
	{
		if (*str == '0')
		{
			while (str[i] == '0')
				i++;
			return (i);
		}
		else
			return (0);
	}
	else
		while (str[i] == '0')
			i++;
	return (intlen(nb) + i);
}
