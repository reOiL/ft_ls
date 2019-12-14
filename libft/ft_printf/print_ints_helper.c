/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:37:54 by eblackbu          #+#    #+#             */
/*   Updated: 2019/12/07 15:38:32 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_reverse_int(t_integers data, t_format format, int count)
{
	count += print_sign(&data, &format);
	count += put_nbr_base(format, data, 10, 0);
	format.width = (format.flags & FLAG_PLUS) && format.precision == 0 && \
		data.ll == 0 ? format.width + 1 : format.width;
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, \
					count_digits(data.ll, 10)))
		{
			ft_putchar(' ');
			format.width--;
			count++;
		}
	}
	return (count);
}

int		print_modified_int(t_integers data, t_format format)
{
	int		count;
	int		width;
	int		flag;

	flag = get_intflag(format, data);
	width = get_intwidth(format, data);
	if (format.flags & FLAG_MINUS)
		return (print_reverse_int(data, format, 0));
	count = ((format.flags & FLAG_ZERO) && (format.width < format.precision \
		|| format.precision < 0)) ? print_sign(&data, &format) : 0;
	if (width > format.precision)
	{
		while (width - flag > ft_max(format.precision, \
		count_digits(data.ll, 10) - is_neg(data.ll)))
		{
			ft_putchar((format.flags & FLAG_ZERO) && \
			format.precision < 0 ? '0' : ' ');
			width--;
			count++;
		}
	}
	count += big_int_condition(&format, &data);
	return (count + put_nbr_base(format, data, 10, 0));
}

int		print_int(t_format format, va_list args)
{
	t_integers	data;

	if (format.modifier & MOD_H)
		data.ll = (short)va_arg(args, int);
	else if (format.modifier & MOD_HH)
		data.ll = (signed char)va_arg(args, int);
	else if (format.modifier & MOD_L)
		data.ll = (long)va_arg(args, long);
	else if (format.modifier & MOD_LL)
		data.ll = (long long)va_arg(args, long long);
	else
		data.ll = (int)va_arg(args, int);
	return (print_modified_int(data, format));
}
