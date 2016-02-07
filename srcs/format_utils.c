/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:55:36 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:55:38 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

int		skip_format(char *str)
{
	int i;

	i = 1;
	if (str[0] == '%')
		while (str[i] && !is_conversion(str[i]) && is_allowed(str + i))
			i++;
	return (str[i] ? i + 1 : i);
}

int		count_format(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += skip_format(str + i) - 1;
			count++;
		}
		i++;
	}
	return (count);
}

int		format_index(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (i);
		i++;
	}
	return (0);
}
