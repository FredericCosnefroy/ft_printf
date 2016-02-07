/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:55:53 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:55:54 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/ft_printf.h"

int		intlen(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*invert_chars(char *str)
{
	char	tmp;
	int		len;
	int		len2;
	int		i;

	len = ft_strlen(str);
	len2 = len;
	i = 0;
	while (i != len2 / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}

char	*add_string(t_format *format, int len, char c, int left)
{
	char str[len + 1];
	char *tmp;

	if (len <= 0)
		return (format->out);
	ft_memset(str, c, len);
	str[len] = '\0';
	if (left)
		tmp = ft_strjoin(str, format->out);
	else
		tmp = ft_strjoin(format->out, str);
	if (format->to_free)
		free(format->out);
	else
		format->to_free = 1;
	format->out = ft_strdup(tmp);
	free(tmp);
	return (format->out);
}
