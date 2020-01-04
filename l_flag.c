#include "args.h"
#include "ft_ls.h"

int		print_fileinfo_l(t_file *subfiles, t_flag flag, char *path)
{
	t_maxlen	maxlen;
	char		*fileinfo;

	fileinfo = NULL;
	sort_files(&subfiles, flag);
	if (flag & FLAG_R)
		ft_printf("%s:\n", path);
	ft_printf("total %lld\n", get_blocks(subfiles));
	maxlen = get_max_lengths(subfiles);
	while (subfiles)
	{
		fileinfo = get_fileinfo(subfiles, maxlen);
		ft_putendl(fileinfo);
		ft_strdel(&fileinfo);
		subfiles = subfiles->next;
	}
}

int		print_files_links(char *filename, t_flag flag, char *path)
{
	t_file		*file;

	add_new_tfile(&file, filename, path);
	print_fileinfo_l(file, flag, path);
	free_all(&file);
}

int		print_dirfiles(char *dirname, t_flag flag, char *path)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file 			*subfiles;
	t_file			*tmp;

	subfiles = NULL;
	if(!(dir = opendir(path))) //понять как прописывать полный путь
		return (print_error(13, path));
	while ((dp = readdir(dir)))
		add_new_tfile(&subfiles, dp->d_name, path);
	closedir(dir);
	print_fileinfo_l(subfiles, flag, path);
	tmp = subfiles;

	//if FLAG_R - пройтись этой же функцией по поддиректориям Вынести в отдельную функцию
	if (flag & FLAG_R)
	{
		del_all_files(&subfiles);
		while (subfiles)
		{
			if (ft_strcmp(subfiles->filename, ".") && ft_strcmp(subfiles->filename, ".."))
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
	if (!only_one)
		ft_printf("./%s:\n", arg_dirs->filename);
	if (S_ISDIR(arg_dirs->s_stat->st_mode))
		print_dirfiles(arg_dirs->filename, flag, ft_strdup(arg_dirs->filename));
	else
		print_files_links(arg_dirs->filename, flag, ".");
}

void		ls_with_l(t_flag flag, t_file *arg_dirs)
{
	int 	only_one;

	only_one = arg_dirs->next ? 0 : 1;
	/* Отсортировать в зависимости от флагов и сначала файлы потом папки
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
