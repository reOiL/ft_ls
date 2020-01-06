//
// Created by Johnny Webber on 04/01/2020.
//

#include "ft_ls.h"
#include <errno.h>

void		print_dir(t_flag flag, t_file *file, int is_many)
{
	DIR			*dir;
	t_dirent	*dp;
	t_file		*subfiles;
	t_file		*subfiles_iter;

	subfiles = NULL;
	if (!(dir = opendir(file->fullpath)))
	{
		if (is_many)
			ft_printf("\n%s:\n", file->fullpath);
		print_error(EACCES, file->filename);
		return ;
	}
	while ((dp = readdir(dir)))//75
	{
		if (!(flag & FLAG_A) && dp->d_name[0] == '.')
			continue;
		add_new_tfile(&subfiles, dp->d_name, file->fullpath);
	}
	closedir(dir);
	sort_by_flag(subfiles, flag);
	subfiles_iter = subfiles;
	if (is_many)
		ft_printf("\n%s:\n", file->fullpath);
	while (subfiles_iter)
	{
		print_file_name(subfiles_iter, flag);
		subfiles_iter = subfiles_iter->next;
	}
	if (flag & FLAG_REC)
	{
		del_all_files(&subfiles);
		subfiles_iter = subfiles;
		while (subfiles_iter)
		{
			if (is_dir(subfiles_iter))
			{
				print_dir(flag, subfiles_iter, 1);
			}
			subfiles_iter = subfiles_iter->next;
		}
	}
	free_all(&subfiles);
}

void		ls_without_l(t_flag flag, t_file *arg_dirs)
{
	int is_many;

	is_many = arg_dirs->next != NULL;
	while (arg_dirs)
	{
		if (!(arg_dirs->s_stat))
			print_error(2, arg_dirs->filename);
		if (is_dir(arg_dirs) <= 0 || flag & FLAG_D)
			print_file_name(arg_dirs, flag);
		else
			print_dir(flag, arg_dirs, is_many);
		arg_dirs = arg_dirs->next;
	}
}