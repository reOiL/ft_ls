/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:15:51 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/07 15:32:37 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "floating.h"

long double		accureit(long double d, t_format format)
{
	double	accur;
	int		i;

	accur = 5;
	i = 0;
	format.precision = format.precision < 0 ? 6 : format.precision;
	while (i++ < format.precision + 1)
		accur /= 10;
	return (d + (d > 0 ? accur : -accur));
}

char			*float_fraction(long double d, int *precision, t_format format)
{
	char	*ret;
	int		i;

	*precision = *precision < 0 ? 6 : *precision;
	if (*precision == 0 || ((long long)d == 0 && *precision == 0))
		return (format.flags & FLAG_SHARP ? ft_strdup(".") : ft_strdup(""));
	if (!(ret = ft_strnew(*precision + (precision != 0))))
		return (NULL);
	d = (d < 0 ? -d : d);
	d = accureit(d, format);
	i = 0;
	ret[0] = '.';
	while (i < *precision)
	{
		d -= (unsigned long long)d;
		d *= 10;
		ret[++i] = ('0' + (unsigned long long)d % 10);
	}
	d -= (unsigned long long)d;
	if (format.precision >= 20 && d * 10 >= 5)
		ret[i] += 1;
	return (ret);
}

int				print_float2(t_format format, char *leading, char *fraction,
		long double d)
{
	int	size;

	size = ft_strlen(leading) + ft_strlen(fraction);
	size += d < 0 ||
			(d > 0 && format.flags & FLAG_PLUS) ||
			(d > 0 && format.flags & FLAG_SPACE);
	if (format.width > size && !(format.flags & FLAG_MINUS) &&
	!(format.flags & FLAG_ZERO))
		size += putchar_count(' ', format.width - size);
	if (d < 0)
		putchar_count('-', 1);
	else if (d > 0 && format.flags & FLAG_PLUS)
		putchar_count('+', 1);
	else if (d > 0 && format.flags & FLAG_SPACE)
		putchar_count(' ', 1);
	if (format.flags & FLAG_ZERO && format.width > size &&
	!(format.flags & FLAG_MINUS))
		size += putchar_count('0', format.width - size);
	ft_putstr(leading);
	ft_putstr(fraction);
	if (format.width > size && (format.flags & FLAG_MINUS))
		size += putchar_count(' ', format.width - size);
	ft_strdel(&leading);
	ft_strdel(&fraction);
	return (size);
}

int				handle_spec(char **leading, char **fraction, long double d)
{
	if (!(*fraction = ft_strdup("")))
		return (-1);
	if (d == PINF && !(*leading = ft_strdup("inf")))
	{
		ft_strdel(fraction);
		return (-1);
	}
	if (d == MINF && !(*leading = ft_strdup("-inf")))
	{
		ft_strdel(fraction);
		return (-1);
	}
	if (d != d && !(*leading = ft_strdup("nan")))
	{
		ft_strdel(fraction);
		return (-1);
	}
	return (1);
}

int				print_float(t_format format, va_list args)
{
	long double	d;
	char		*leading;
	char		*fraction;

	if (format.modifier & MOD_LD)
		d = va_arg(args, long double);
	else
		d = va_arg(args, double);
	if (d == PINF || d == MINF || d != d)
	{
		if (handle_spec(&leading, &fraction, d) < 0)
			return (0);
	}
	else
	{
		if (!(leading = ft_itoa_base(d < 0 ? -(long long)accureit(d, format)
				: (long long)accureit(d, format), 10)))
			return (0);
		if (!(fraction = float_fraction(d, &format.precision, format)))
		{
			ft_strdel(&leading);
			return (0);
		}
	}
	return (print_float2(format, leading, fraction, d));
}
