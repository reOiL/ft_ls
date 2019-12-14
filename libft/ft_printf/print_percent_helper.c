/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:50:14 by eblackbu          #+#    #+#             */
/*   Updated: 2019/11/16 14:50:33 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_format format)
{
	int		count;

	count = 0;
	if (format.flags & FLAG_MINUS)
	{
		ft_putchar('%');
		count++;
		while (count < format.width)
		{
			ft_putchar(' ');
			count++;
		}
		return (count);
	}
	else
	{
		while (format.width-- > 1)
		{
			count++;
			ft_putchar(format.flags & FLAG_ZERO ? '0' : ' ');
		}
		ft_putchar('%');
		return (count + 1);
	}
}
