/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:11:13 by jwebber           #+#    #+#             */
/*   Updated: 2020/01/06 13:11:53 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(t_file *file)
{
	if (!file)
		return (-1);
	return (S_ISDIR(file->s_stat->st_mode));
}

int		is_link(t_file *file)
{
	if (!file)
		return (-1);
	return (S_ISLNK(file->s_stat->st_mode));
}

int		is_exec(t_file *file)
{
	if (!file)
		return (-1);
	return (file->s_stat->st_mode & S_IXUSR);
}

void	sort_by_flag(t_file *lst, t_flag flag)
{
	if ((flag & FLAG_F) && !(flag & FLAG_D))
		sort_lst(lst, cmp_flag_f, 1);
	else if ((flag & FLAG_T))
		sort_lst(lst, cmp_flag_t, flag & FLAG_R ? 1 : 0);
	else if (!(flag & FLAG_D))
		sort_lst(lst, cmp_flag_ascii, flag & FLAG_R ? 0 : 1);
}

void	print_file_name(t_file *file, t_flag flag)
{
	if (is_dir(file) && flag & FLAG_G)
		ft_printf("\e[1m{cyan}");
	else if (is_link(file) && flag & FLAG_G)
		ft_printf("\e[1m{magenta}");
	else if (is_exec(file) && flag & FLAG_G)
		ft_printf("{red}");
	ft_printf("%s\n", file->filename);
	if (flag & FLAG_G)
		ft_printf("{eoc}");
}
