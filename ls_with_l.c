#include "ft_ls.h"

int		print_fileinfo_l(t_file **subfiles, t_flag flag, char *path)
{
	t_maxlen	maxlen;
	char		*fileinfo;
	t_file		*tmp;

	sort_files(subfiles, flag);
	maxlen = get_max_lengths(*subfiles);
	tmp = *subfiles;
	while (tmp)
	{
		fileinfo = get_fileinfo(tmp, maxlen);
		ft_putendl(fileinfo);
		ft_strdel(&fileinfo);
		tmp = tmp->next;
	}
}

int		print_files_links(char *filename, t_flag flag, char *path)
{
	t_file		*file;

	file = NULL;
	add_new_tfile(&file, filename, path);
	print_fileinfo_l(&file, flag, path);
	free_all(&file);
}

int		print_dirfiles(char *dirname, t_flag flag, char *path)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file 			*subfiles;
	t_file			*tmp;

	subfiles = NULL;
	if (flag & FLAG_REC)
		ft_printf("%s:\n", path);
	if(!(dir = opendir(path)))
	{
		ft_strdel(&path);
		return (print_error(13, dirname));
	}
	while ((dp = readdir(dir)))
	{
		if (!(flag & FLAG_A) && dp->d_name[0] == '.')
			continue;
		add_new_tfile(&subfiles, dp->d_name, path);
	}
	closedir(dir);
	if (subfiles)
		ft_printf("total %lld\n", get_blocks(subfiles));
	print_fileinfo_l(&subfiles, flag, path);

	tmp = subfiles;
	//if FLAG_REC - пройтись этой же функцией по поддиректориям Вынести в отдельную функцию
	if (flag & FLAG_REC)
	{
		del_all_files(&subfiles);
		tmp = subfiles;
		while (subfiles)
		{
			if (is_dir(subfiles))
			{
				ft_putchar('\n');
				print_dirfiles(subfiles->filename, flag, path_join(path, subfiles->filename));
			}
			subfiles = subfiles->next;
		}
	}
	free_all(&tmp);
	ft_strdel(&path);
}

void		print_files_l(t_flag flag, t_file *arg_dirs, int only_one)
{
	if (!only_one && S_ISDIR(arg_dirs->s_stat->st_mode))
		ft_printf("%s:\n", arg_dirs->fullpath);
	if (S_ISDIR(arg_dirs->s_stat->st_mode))
	{
		print_dirfiles(arg_dirs->filename, flag, ft_strdup(arg_dirs->filename));
		if (!only_one && arg_dirs->next)
			ft_putchar('\n');
	}
	else
	{
		print_files_links(arg_dirs->filename, flag, ".");
		if (arg_dirs->next && S_ISDIR(arg_dirs->next->s_stat->st_mode))
			ft_putchar('\n');
	}
}

void		ls_with_l(t_flag flag, t_file *arg_dirs)
{
	int 	only_one;

	only_one = (arg_dirs->next && !(flag & FLAG_REC)) ? 0 : 1;
	while (arg_dirs)
	{
		if (!(arg_dirs->s_stat->st_mode))
			print_error(2, arg_dirs->filename);
		else
			print_files_l(flag, arg_dirs, only_one);
		arg_dirs = arg_dirs->next;
	}
}
