/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:50:14 by jwebber           #+#    #+#             */
/*   Updated: 2020/01/07 10:50:15 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_flag_u(t_file *f1, t_file *f2)
{
	if (f1->s_stat->st_atimespec.tv_sec > f2->s_stat->st_atimespec.tv_sec)
		return (1);
	if (f1->s_stat->st_atimespec.tv_sec < f2->s_stat->st_atimespec.tv_sec)
		return (-1);
	return (-cmp_flag_ascii(f1, f2));
}

int	cmp_flag_ubig(t_file *f1, t_file *f2)
{
	if (f1->s_stat->st_birthtimespec.tv_sec > f2->s_stat->st_birthtimespec.tv_sec)
		return (1);
	if (f1->s_stat->st_birthtimespec.tv_sec < f2->s_stat->st_birthtimespec.tv_sec)
		return (-1);
	return (-cmp_flag_ascii(f1, f2));
}
