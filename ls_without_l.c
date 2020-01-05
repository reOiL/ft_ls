//
// Created by Johnny Webber on 04/01/2020.
//

#include "ft_ls.h"


void		print_dir(t_flag flag, t_file *file, char *fullpath)
{
	DIR			*dir;
	t_dirent	*dp;
	t_file		*subfiles;
	t_file		*subfiles_iter;

	subfiles = NULL;
	if (!(dir = opendir(fullpath == NULL ? file->filename : fullpath)))
		return ; //TODO: delete fullpath
	while ((dp = readdir(dir)))
	{
		if (!(flag & FLAG_a) && dp->d_name[0] == '.')
			continue;
		add_new_tfile(&subfiles, dp->d_name, fullpath ? fullpath : ".");
	}
	closedir(dir);
	if ((flag & FLAG_t))
		sort_lst(subfiles, cmp_flag_t, flag & FLAG_r ? 1 : 0);
	else
		sort_lst(subfiles, cmp_flag_ascii, flag & FLAG_r ? 0 : 1);
	subfiles_iter = subfiles;
	if (fullpath)
		ft_printf("\n%s:\n", fullpath);
	while (subfiles_iter)
	{
		if (is_dir(subfiles_iter))
			ft_printf("{cyan}%s{eoc}\n", subfiles_iter->filename);
		else
			ft_printf("%s\n", subfiles_iter->filename);
		subfiles_iter = subfiles_iter->next;
	}
	if (flag & FLAG_R)
	{
		subfiles_iter = subfiles;
		while (subfiles_iter)
		{
			if (is_dir(subfiles_iter))
			{
				print_dir(flag, subfiles_iter, path_join(fullpath ? fullpath : file->filename, subfiles_iter->filename));
			}
			subfiles_iter = subfiles_iter->next;
		}
	}
	if (fullpath)
		ft_strdel(&fullpath);
	del_all_files(&subfiles);
}

void		ls_without_l(t_flag flag, t_file *arg_dirs)
{
	while (arg_dirs)
	{
		if (!(arg_dirs->s_stat))
			print_error(2, arg_dirs->filename);
		if (is_dir(arg_dirs) <= 0)
			ft_printf("%s\n", arg_dirs->filename);
		else
			print_dir(flag, arg_dirs, NULL);
		arg_dirs = arg_dirs->next;
	}
}