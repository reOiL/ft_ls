/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_numbers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:44:23 by eblackbu          #+#    #+#             */
/*   Updated: 2019/12/07 16:12:20 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero_number(t_format format, t_integers val)
{
	if (!format.precision && val.ull == 0 && \
		(format.type == 'x' || format.type == 'X' \
		|| (format.type == 'o' && !(format.flags & FLAG_SHARP)) \
		|| format.type == 'u' || format.type == 'p'))
		return (1);
	if (!format.precision && val.ll == 0 && \
		(format.type == 'd' || format.type == 'i'))
		return (1);
	return (0);
}

int		get_intflag(t_format format, t_integers data)
{
	if ((format.width > count_digits(data.ll, 10) && \
	(format.flags & FLAG_SPACE)) || (format.flags & \
		FLAG_PLUS) || (is_neg(data.ll)))
		return (1);
	return (0);
}

int		get_intwidth(t_format format, t_integers data)
{
	if ((format.flags & FLAG_PLUS) && format.precision == 0 && data.ll == 0)
		return (format.width + 1);
	return (format.width);
}

int		big_int_condition(t_format *format, t_integers *data)
{
	if (!(((*format).flags & FLAG_PLUS || \
	(*format).flags & FLAG_SPACE) && ((*format).flags & FLAG_ZERO)) || \
	((*format).width >= (*format).precision && (*format).precision > -1))
		return (print_sign(data, format));
	return (0);
}

int		get_unswidth(t_format format, t_integers data)
{
	int n;

	n = format.width;
	n -= (format.type == 'o') ? 1 : 2;
	n += (format.type == 'o' && format.precision != -1 && \
	format.precision > count_digits_uns(data.ull, 8)) ? 1 : 0;
	return (n);
}
