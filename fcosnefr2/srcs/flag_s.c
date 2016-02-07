/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:38:32 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/03/11 15:23:17 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_ws(t_format f, wchar_t *wstr)
{
	const int	len = 4 * ft_wstrlen(wstr);
	char		*str;
	char		*ret;
	int			length;

	if (!wstr)
		return (NULL);
	str = ft_strnew(len);
	length = ft_wstrnconv(str, wstr,
			(f.precision_set && len > f.precision) ? f.precision : len);
	ret = ft_strsub(str, 0, length);
	free(str);
	return (ret);
}

static char	*get_str(t_format f, va_list *ap, char *c, int *left)
{
	char	*str;

	*c = (ft_strchr(f.flags, '0') ? '0' : ' ');
	*left = (ft_strchr(f.flags, '-') ? 0 : 1);
	if (f.conversion.label == 'S' || ft_strequ(f.modifier, "l"))
		str = flag_ws(f, (va_arg(*ap, wchar_t *)));
	else
		str = va_arg(*ap, char *);
	return (str);
}

int			flag_s(t_format f, va_list *ap)
{
	char	*str;
	char	c;
	int		left;
	int		len;

	str = get_str(f, ap, &c, &left);
	f.to_free = 1;
	if (!str)
	{
		free(str);
		str = "(null)";
		f.to_free = 0;
	}
	if (f.precision_set && f.conversion.label != 'S' &&
			!ft_strequ(f.modifier, "l"))
		f.out = ft_strsub(str, 0, f.precision);
	else
		f.out = ft_strdup(str);
	f.out = add_string(&f, f.length - ft_strlen(f.out), (left ? c : ' '), left);
	ft_putstr(f.out);
	len = ft_strlen(f.out);
	free(f.out);
	return (len);
}
