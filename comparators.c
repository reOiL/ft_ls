/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:12:26 by jwebber           #+#    #+#             */
/*   Updated: 2020/01/06 13:13:45 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_flag_t(t_file *f1, t_file *f2)
{
	if (f1->s_stat->st_mtimespec.tv_sec > f2->s_stat->st_mtimespec.tv_sec)
		return (1);
	if (f1->s_stat->st_mtimespec.tv_sec < f2->s_stat->st_mtimespec.tv_sec)
		return (-1);
	return (-cmp_flag_ascii(f1, f2));
}

int	cmp_flag_ascii(t_file *f1, t_file *f2)
{
	return (ft_strcmp(f1->filename, f2->filename));
}

int	cmp_file_type(t_file *f1, t_file *f2)
{
	int a;
	int b;

	a = is_dir(f1);
	b = is_dir(f2);
	if (a && !b)
		return (1);
	if (!a && b)
		return (1);
	return (0);
}

int	cmp_file_type_ascii(t_file *f1, t_file *f2)
{
	int a;
	int b;

	a = is_dir(f1);
	b = is_dir(f2);
	if (a && !b)
		return (1);
	if (!a && b)
		return (1);
	return (0);
}

int	cmp_flag_f(t_file *f1, t_file *f2)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = f1->filename;
	s2 = f2->filename;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((ft_tolower(s1[i]) - ft_tolower(s2[i])) != 0)
			return ((unsigned char)ft_tolower(s1[i]) - ft_tolower(s2[i]));
		i++;
	}
	return (0);
}
