/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:28:50 by eblackbu          #+#    #+#             */
/*   Updated: 2019/11/16 14:29:40 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_len(long long val, int base)
{
	if (val == 0)
		return (1);
	return (calc_len(val / base, base) + 1);
}

char	cast_base(unsigned short val)
{
	char		c;

	c = '0';
	if (val >= 0 && val <= 9)
		c += val;
	else if (val >= 10 && val <= 16)
		c = (val - 10) + 'A';
	return (c);
}

void	itoa_2(char **array, long long val, int base, long long index)
{
	if (val / base != 0)
		itoa_2(array, val / base, base, index - 1);
	(*array)[index] = cast_base(val % base);
}

char	*ft_itoa_base(long long ll, int base)
{
	char		*array;
	long long	len;
	int			is_minus;

	if (base < 2 || base > 16)
		return (ft_strdup("0"));
	is_minus = 0;
	if ((unsigned long long)ll == (unsigned long long)MIN_LLONG + 1)
		return (ft_strdup("9223372036854775808"));
	if (ll < 0)
	{
		if (base == 10)
			is_minus = 1;
		ll *= -1;
	}
	len = calc_len(ll, base) + (ll == 0);
	array = ft_strnew((len + is_minus));
	if (is_minus)
		array[0] = '-';
	itoa_2(&array, ll, base, len - (2 - is_minus));
	array[len - (1 - is_minus)] = '\0';
	return (array);
}
