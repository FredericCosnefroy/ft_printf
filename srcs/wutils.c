/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:54:01 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 14:52:32 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_wstrlen(wchar_t *wstr)
{
	unsigned int	i;

	if (wstr == NULL)
		return (0);
	i = 0;
	while (wstr[i] != '\0')
		i++;
	return (i);
}

int				ft_wstrconv(char *buff, wchar_t *wstr)
{
	int				i;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0)
		len += ft_widetoa(buff + len, wstr[i]);
	return (len);
}

int				ft_wstrnconv(char *buff, wchar_t *wstr, int n)
{
	int				i;
	int				tmp;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0)
	{
		tmp = ft_widetoa(buff + len, wstr[i]);
		if ((tmp + len) > n)
			break ;
		len += tmp;
	}
	return (len);
}

int				ft_widetoa(char *buff, wchar_t w)
{
	if (w < 0x80)
		return (*buff = ((w & 0x7F) | 0), 1);
	else if (w < 0x800)
	{
		*(buff++) = ((w >> 6) & 0x1F) | 0xC0;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (w < 0x10000)
	{
		*(buff++) = ((w >> 12) & 0xF) | 0xE0;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (w < 0x110000)
	{
		*(buff++) = ((w >> 18) & 0x7) | 0xF0;
		*(buff++) = ((w >> 12) & 0x3F) | 0x80;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}
