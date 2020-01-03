#include "args.h"
#include "ft_ls.h"

int			print_fileinfo_l(t_file *subfiles, t_maxlen maxlen, t_flag flag)
{
	char	*fileinfo;

	fileinfo = NULL;
	while (subfiles)
	{
		fileinfo = get_fileinfo(subfiles, maxlen);
		ft_printf("%s\n", fileinfo);
		ft_strdel(&fileinfo);
		subfiles = subfiles->next;
	}
}

int			print_dirfiles(char *dirname, t_flag flag)
{
	DIR				*dir;
	struct dirent	*dp;
	t_maxlen		maxlen;
	t_file 			*subfiles;

	subfiles = NULL;
	if(!(dir = opendir(dirname))) //понять как прописывать полный путь
		return (print_error(13, dirname));
	while (dp = readdir(dir))
		add_new_tfile(&subfiles, dp->d_name);
	closedir(dir);
	ft_printf("total %lld\n", get_blocks(subfiles));
	//TODO сортировка в зависимости от флага
	maxlen = get_max_lengths(subfiles);
	print_fileinfo_l(subfiles, maxlen, flag);
	//if FLAG_R - пройтись этой же функцией по поддиректориям
}

void		print_files_l(t_flag flag, t_file *arg_dirs, int only_one)
{
	if (!only_one)
		ft_printf("./%s:\n", arg_dirs->filename);
	if (S_ISDIR(arg_dirs->s_stat->st_mode))
		print_dirfiles(arg_dirs->filename, flag);
	/*
	else
		добавить вывод для аргумента-файла / аргумента-ссылки
	 */
}

void		ls_with_l(t_flag flag, t_file *arg_dirs)
{
	int 	only_one;

	only_one = arg_dirs->next ? 0 : 1;
	/* Отсортировать в зависимости от флагов
	if (flag & FLAG_r)
		sort_back(&arg_dirs);
	else if (flag & FLAG_t)
		sort_by_time(&arg_dirs);
	*/
	while (arg_dirs)
	{
		if (!(arg_dirs->s_stat))
			print_error(2, arg_dirs->filename);
		else
			print_files_l(flag, arg_dirs, only_one);
		arg_dirs = arg_dirs->next;
	}
}
