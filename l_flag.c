#include "args.h"
#include "ft_ls.h"

int			print_fileinfo_l(struct dirent *dp)
{
	char 	*output;
	struct stat	stats;

	stat(dp->d_name, &stats);
	output = get_access_rights(dp, stats);

}


int			print_dirfiles(char *filename)
{
	DIR				*dir;
	struct dirent	*dp;
	int 			len_hlinks;
	int 			len_names;


	if(!(dir = opendir(filename)))
		return (print_error(13, filename));
	while ((dp = readdir(dir)))
	{
		print_fileinfo_l(dp);
	}
	closedir(dir);
}

void		print_files_l(t_flag flag, t_file *files, int only_one)
{
	if (!only_one)
		ft_printf("./%s:\n", files->filename);
	if (S_ISDIR(files->s_stat->st_mode))
	{
		ft_printf("total %lld\n", files->s_stat->st_size);
		print_dirfiles(files->filename);
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
