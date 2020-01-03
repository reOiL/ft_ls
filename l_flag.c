#include "args.h"
#include "ft_ls.h"

int			print_fileinfo_l(t_file *subfiles, t_maxlen maxlen)
{
	while (subfiles)
	{
		//TODO ft_printf(get_fileinfo(subfiles));
		subfiles = subfiles->next;
	}
}


int			print_dirfiles(char *filename, t_flag flag)
{
	DIR				*dir;
	struct dirent	*dp;
	t_maxlen		max_len;
	t_file 			*subfiles;

	subfiles = NULL;
	if(!(dir = opendir(filename)))
		return (print_error(13, filename));
	//TODO max_len = get_max_lengths(dir);
	while (dp = readdir(dir))
		add_new_dir(&subfiles, dp->d_name);
	//TODO сортировка в зависимости от флага
	//print_fileinfo_l(subfiles, maxlen, flag);
	closedir(dir);
	//if FLAG_R - пройтись этой же функцией по поддиректориям
}

void		print_files_l(t_flag flag, t_file *files, int only_one)
{
	if (!only_one)
		ft_printf("./%s:\n", files->filename);
	if (S_ISDIR(files->s_stat->st_mode))
	{
		ft_printf("total %lld\n", files->s_stat->st_size);
		print_dirfiles(files->filename, flag);
	}
}

void		ls_with_l(t_flag flag, t_file *files)
{
	int 	only_one;

	only_one = files->next ? 0 : 1;
	/* Отсортировать в зависимости от флагов
	if (flag & FLAG_r)
		sort_back(&files);
	else if (flag & FLAG_t)
		sort_by_time(&files);
	*/
	while (files)
	{
		if (!(files->s_stat))
			print_error(2, files->filename);
		else
			print_files_l(flag, files, only_one);
		files = files->next;
	}
}
