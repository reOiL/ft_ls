/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:28:35 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/07 15:33:10 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		putchar_count(char c, size_t count)
{
	char	*p;

	if (!(p = ft_strnew(count)))
		return (0);
	ft_memset(p, c, count);
	ft_putstr(p);
	ft_strdel(&p);
	return (count);
}
