/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:36:50 by eblackbu          #+#    #+#             */
/*   Updated: 2019/12/07 16:24:53 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_flags(const char *str, int *it)
{
	unsigned int	res;

	res = 0;
	if (str == NULL || it == NULL)
		return (0);
	while (1)
	{
		if (*str == '-')
			res |= FLAG_MINUS;
		else if (*str == '+')
			res |= FLAG_PLUS;
		else if (*str == ' ')
			res |= FLAG_SPACE;
		else if (*str == '#')
			res |= FLAG_SHARP;
		else if (*str == '0')
			res |= FLAG_ZERO;
		else
			break ;
		(*it)++;
		str++;
	}
	return (res);
}

char			get_type(const char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p')
		return (*str);
	else if (*str == 'd' || *str == 'i' || *str == 'o')
		return (*str);
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		return (*str);
	else if (*str == 'f' || *str == '%')
		return (*str);
	else
		return (0);
}

int				get_width(const char *str, \
		int *i, va_list args, t_format *format)
{
	int				width;

	width = 0;
	if (*str == '*')
	{
		(*i)++;
		str++;
		format->width = va_arg(args, int);
		if (format->width < 0)
		{
			format->width *= -1;
			format->flags |= FLAG_MINUS;
		}
		if (!ft_isdigit(*str))
			width = format->width;
	}
	while (ft_isdigit(*str))
	{
		width = *str++ - '0' + width * 10;
		(*i)++;
	}
	return (width);
}

int				get_precision(const char *str, int *i, va_list args)
{
	int				precision;

	precision = -1;
	if (*str++ == '.')
	{
		(*i)++;
		if (*str == '*')
		{
			precision = va_arg(args, int);
			(*i)++;
			return (precision < 0 ? -1 : precision);
		}
		precision = 0;
		while (ft_isdigit(*str))
		{
			precision = precision == -1 ? \
			*str - '0' : (*str - '0') + precision * 10;
			str++;
			(*i)++;
		}
	}
	return (precision);
}

int				get_modifier(const char *str, int *i)
{
	if (*str == 'l' || *str == 'h' || *str == 'L')
	{
		(*i)++;
		if (*str == 'L')
			return (MOD_LD);
		if ((*(str + 1) == 'h' && *str == 'h') \
				|| (*(str + 1) == 'l' && *str == 'l'))
		{
			(*i)++;
			return (*str == 'h' ? MOD_HH : MOD_LL);
		}
		return (*str == 'h' ? MOD_H : MOD_L);
	}
	return (0);
}
