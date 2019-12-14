/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:30:48 by eblackbu          #+#    #+#             */
/*   Updated: 2019/12/07 15:35:16 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_x(t_format format, t_integers data)
{
	if (format.type == 'x')
	{
		ft_putstr("0x");
		return (2);
	}
	if (format.type == 'X')
	{
		ft_putstr("0X");
		return (2);
	}
	if (format.type == 'o' && format.precision <= count_digits_uns(data.ull, 8))
	{
		ft_putstr("0");
		return (1);
	}
	return (0);
}

char	*ft_tolower_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int		print_reverse_uns(t_integers data, t_format format, int count, int base)
{
	if ((format.flags & FLAG_SHARP) && data.ull != 0)
	{
		count += print_x(format, data);
		format.width -= count;
	}
	count += put_nbr_base(format, data, base, 1);
	if (format.width > format.precision)
	{
		while (format.width > \
	ft_max(format.precision, count_digits_uns(data.ull, base)))
		{
			ft_putchar(' ');
			format.width--;
			count++;
		}
	}
	return (count);
}

int		print_modified_uns(t_integers data, t_format format, int base)
{
	int		count;

	count = 0;
	if (format.flags & FLAG_MINUS)
		return (print_reverse_uns(data, format, count, base));
	if ((format.flags & FLAG_SHARP) && data.ull != 0 && format.type != 'u')
	{
		format.width = get_unswidth(format, data);
		count += (format.flags & FLAG_ZERO && format.precision == -1) \
			? print_x(format, data) : 0;
	}
	if (format.width > format.precision)
	{
		while (format.width > ft_max(format.precision, \
		count_digits_uns(data.ull, base)))
		{
			ft_putchar(format.flags & FLAG_ZERO &&
			format.precision == -1 ? '0' : ' ');
			format.width--;
			count++;
		}
	}
	count += ((format.flags & FLAG_SHARP) && data.ull != 0 && !(format.flags \
	& FLAG_ZERO && format.precision == -1)) ? print_x(format, data) : 0;
	return (count + put_nbr_base(format, data, base, 1));
}

int		print_int_unsigned(t_format format, va_list args)
{
	t_integers	data;

	if (format.modifier & MOD_H)
		data.ull = (unsigned short)va_arg(args, int);
	else if (format.modifier & MOD_HH)
		data.ull = (unsigned char)va_arg(args, int);
	else if (format.modifier & MOD_L)
		data.ull = (unsigned long)va_arg(args, unsigned long);
	else if (format.modifier & MOD_LL)
		data.ull = (unsigned long long)va_arg(args, unsigned long long);
	else
		data.ull = (unsigned int)va_arg(args, unsigned int);
	if (format.type == 'x' || format.type == 'X')
		return (print_modified_uns(data, format, 16));
	if (format.type == 'o')
		return (print_modified_uns(data, format, 8));
	return (print_modified_uns(data, format, 10));
}
