/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:17:38 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/14 11:26:31 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

int main (int argc, char **argv)
{
	ft_printf("%i {cyan}%s{eoc}\n", argc, *argv);
	return (0);
}
