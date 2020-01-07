/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_with_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:18:19 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 14:40:18 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "args.h"

void		print_fileinfo_l(t_file **subfiles, t_flag flag)
{
	t_maxlen	maxlen;
	char		*fileinfo;
	t_file		*tmp;

	sort_files(subfiles, flag);
	maxlen = get_max_lengths(*subfiles);
	tmp = *subfiles;
	while (tmp)
	{
		fileinfo = get_fileinfo(tmp, maxlen, flag);
		ft_putendl(fileinfo);
		ft_strdel(&fileinfo);
		tmp = tmp->next;
	}
}

void		print_files_links(char *filename, t_flag flag, char *path)
{
	t_file		*file;

	file = NULL;
	add_new_tfile(&file, filename, path);
	print_fileinfo_l(&file, flag);
	free_all(&file);
}

int			print_dirfiles(char *dirname, t_flag flag, char *path, int only_one)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file			*subfiles;

	subfiles = NULL;
	if ((flag & FLAG_REC) && !(flag & FLAG_D) && !only_one)
		ft_printf("%s:\n", path);
	if (!(dir = opendir(path)))
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
	if (closedir(dir) < 1 && subfiles)
		ft_printf("total %lld\n", get_blocks(subfiles));
	print_fileinfo_l(&subfiles, flag);
	subfiles = go_rec(&subfiles, flag, path);
	free_all(&subfiles);
	ft_strdel(&path);
	return (0);
}

void		print_files_l(t_flag flag, t_file *arg_dirs, int only_one)
{
	if (!only_one && S_ISDIR(arg_dirs->s_stat->st_mode) && \
	!(flag & FLAG_REC) && !(flag & FLAG_D))
		ft_printf("%s:\n", arg_dirs->fullpath);
	if (S_ISDIR(arg_dirs->s_stat->st_mode) && !(flag & FLAG_D))
	{
		print_dirfiles(arg_dirs->filename, flag, \
				ft_strdup(arg_dirs->filename), only_one);
		if (!only_one && arg_dirs->next)
			ft_putchar('\n');
	}
	else
	{
		print_files_links(arg_dirs->filename, flag, ".");
		if (arg_dirs->next && \
		S_ISDIR(arg_dirs->next->s_stat->st_mode) && !(flag & FLAG_D))
			ft_putchar('\n');
	}
}

void		ls_with_l(t_flag flag, t_file *arg_dirs)
{
	int		only_one;

	only_one = (arg_dirs->next) ? 0 : 1;
	while (arg_dirs)
	{
		if (!(arg_dirs->s_stat->st_mode))
			print_error(2, arg_dirs->filename);
		else
			print_files_l(flag, arg_dirs, only_one);
		arg_dirs = arg_dirs->next;
	}
}
