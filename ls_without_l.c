//
// Created by Johnny Webber on 04/01/2020.
//

#include "ft_ls.h"


void		print_dir(t_flag flag, t_file *file)
{
	DIR			*dir;
	t_dirent	*dp;
	t_file		*subfiles;
	t_file		*subfiles_iter;

	subfiles = NULL;
	if (!(dir = opendir(file->filename)))
		return ;
	while ((dp = readdir(dir)))
	{
		if (!(flag & FLAG_a) && dp->d_name[0] == '.')
			continue;
		add_new_tfile(&subfiles, dp->d_name, file->filename);
	}
	closedir(dir);
	if ((flag & FLAG_t))
		sort_lst(subfiles, cmp_flag_t, flag & FLAG_r ? 1 : 0);
	else
		sort_lst(subfiles, cmp_flag_ascii, flag & FLAG_r ? 0 : 1);
	subfiles_iter = subfiles;
	while (subfiles_iter)
	{
		time_t t = subfiles_iter->s_stat->st_mtimespec.tv_sec;
		struct tm lt;
		localtime_r(&t, &lt);
		ft_printf("%i:%02i ", lt.tm_hour, lt.tm_min);
		if (is_dir(subfiles_iter))
			ft_printf("{cyan}%s{eoc}\n", subfiles_iter->filename);
		else
			ft_printf("%s\n", subfiles_iter->filename);
		subfiles_iter = subfiles_iter->next;
	}
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
			print_dir(flag, arg_dirs);
		arg_dirs = arg_dirs->next;
	}
}