#include "ft_ls.h"

void	del_tfile(t_file **files)
{
	if ((*files)->s_stat)
		free((*files)->s_stat);
	if ((*files)->filename)
		free((*files)->filename);
	if ((*files)->fullpath)
		free((*files)->fullpath);
	free(*files);
}

t_file		*new_tfile(char *filename, char *path)
{
	t_file	*item;

	item = (t_file*)malloc(sizeof(t_file));
	if (item == NULL)
		return (NULL);
	item->next = NULL;
	item->filename = ft_strdup(filename);
	item->s_stat = (struct stat*)malloc(sizeof(struct stat));
	item->fullpath = ft_strcmp(path, ".") ? path_join(path, filename) : ft_strdup(filename);
	lstat(item->fullpath, item->s_stat);
	return (item);
}

void		add_new_tfile(t_file **files, char *filename, char *path)
{
	t_file		*tmp_prev;
	t_file		*tmp_next;

	tmp_prev = NULL;
	tmp_next = *files;
	while (tmp_next)
	{
		tmp_prev = tmp_next;
		tmp_next = tmp_next->next;
	}
	if (tmp_prev)
		tmp_prev->next = new_tfile(filename, path);
	else
		*files = new_tfile(filename, path);
}