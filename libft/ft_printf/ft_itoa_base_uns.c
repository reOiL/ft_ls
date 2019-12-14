/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:53:18 by eblackbu          #+#    #+#             */
/*   Updated: 2019/11/16 14:53:51 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calc_len_uns(unsigned long long val, int base)
{
	if (val == 0)
		return (1);
	return (calc_len(val / base, base) + 1);
}

void	itoa_2_uns(char **array, unsigned long long val, \
		int base, long long index)
{
	if (val / base != 0)
		itoa_2_uns(array, val / base, base, index - 1);
	(*array)[index] = cast_base(val % base);
}

char	*ft_itoa_base_uns(unsigned long long ull, int base)
{
	char		*array;
	long long	len;

	if (base < 2 || base > 16)
	{
		array = ft_strnew(1);
		array[0] = '0';
		return (array);
	}
	len = calc_len_uns(ull, base) + (ull == 0);
	array = ft_strnew(len);
	itoa_2_uns(&array, ull, base, len - 2);
	array[len - 1] = '\0';
	return (array);
}
