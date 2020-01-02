//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"

t_file	*get_directory_info(char *path)
{
	DIR				*dir;
	t_file			*file;

	dir = opendir(path);
	if (!dir)
		return (NULL);
	closedir(dir);
	if (!(file = ft_memalloc(sizeof(t_file))))
		return (NULL);
	if (!(file->filename = ft_strdup(path)))
		return (free_t_file(file, 0));
	if (stat(file->filename, &file->s_stat) < 0)
		return (free_t_file(file, 0));
	return (file);
}

t_list	*get_all_directory(char *path)
{
	DIR				*dir;
	t_list 			*lst;
	t_list 			*temp_lst;
	t_file 			*temp_file;
	char 			*full_path;
	struct dirent	*dp;

	lst = NULL;
	if(!(dir = opendir(path)))
		return (NULL);
	while ((dp = readdir(dir)))
	{
		if (dp->d_type == DT_DIR) // TODO: think about protect
		{
			full_path = path_join(path, dp->d_name);
			temp_file = get_directory_info(full_path);
			ft_strdel(&full_path);
			ft_strdel(&temp_file->filename);
			temp_file->filename = ft_strdup(dp->d_name);
			temp_lst = ft_lstnew(NULL, sizeof(t_file));
			temp_lst->content = temp_file;
			ft_lstadd(&lst, temp_lst);
		}

	}
	closedir(dir);
	return (lst);
}