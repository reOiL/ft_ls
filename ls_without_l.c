/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_without_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:15:13 by jwebber           #+#    #+#             */
/*   Updated: 2020/01/06 13:19:56 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

int			print_dir1(t_flag flag, t_file *file, t_file **subfiles, int ismany)
{
	DIR			*dir;
	t_dirent	*dp;

	(*subfiles) = NULL;
	if (!(dir = opendir(file->fullpath)))
	{
		if (ismany)
			ft_printf("\n%s:\n", file->fullpath);
		print_error(EACCES, file->filename);
		return (-1);
	}
	while ((dp = readdir(dir)))
	{
		if (!(flag & FLAG_A) && dp->d_name[0] == '.')
			continue;
		add_new_tfile(subfiles, dp->d_name, file->fullpath);
	}
	closedir(dir);
	sort_by_flag(*subfiles, flag);
	return (0);
}

void		print_dir(t_flag flag, t_file *file, int is_many, int is_first)
{
	t_file		*subfiles;
	t_file		*subfiles_iter;

	if (print_dir1(flag, file, &subfiles, is_many) == -1)
		return ;
	subfiles_iter = subfiles;
	if (!is_first)
		ft_printf("\n");
	if (is_many)
		ft_printf("%s:\n", file->fullpath);
	while (subfiles_iter)
	{
		print_file_name(subfiles_iter, flag);
		subfiles_iter = subfiles_iter->next;
	}
	if (flag & FLAG_REC)
	{
		subfiles_iter = subfiles;
		while (subfiles_iter)
		{
			if (is_dir(subfiles_iter) && !is_spec_dir(subfiles_iter))
				print_dir(flag, subfiles_iter, 1, 0);
			subfiles_iter = subfiles_iter->next;
		}
	}
	//if (file->next)
	//	ft_printf("\n");
	free_all(&subfiles);
}

void		ls_without_l(t_flag flag, t_file *arg_dirs)
{
	int is_many;
	int	is_first;

	is_many = arg_dirs->next != NULL;
	is_first = 1;
	while (arg_dirs)
	{
		if (!(arg_dirs->s_stat) || arg_dirs->s_stat->st_mode == 0)
			print_error(2, arg_dirs->filename);
		else if (is_dir(arg_dirs) <= 0 || flag & FLAG_D)
			print_file_name(arg_dirs, flag);
		else
			print_dir(flag, arg_dirs, is_many, is_first);
		is_first = 0;
		arg_dirs = arg_dirs->next;
	}
}
