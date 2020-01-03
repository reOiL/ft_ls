#include "ft_ls.h"

void	del_tfile(t_file **files)
{
	if ((*files)->s_stat)
		free((*files)->s_stat);
	if ((*files)->filename)
		free((*files)->filename);
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
	if (ft_strcmp(path, "."))
		stat(path_join(path, filename), item->s_stat);
	else
		stat(filename, item->s_stat);
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

void	del_all_hidden(t_file **files) //ПОТОМ УКОРОТИТЬ ПО СТРОКАМ
{
	t_file		*tmp_prev;
	t_file		*tmp_next;

	tmp_prev = NULL;
	tmp_next = *files;
	while (tmp_next)
	{
		if (tmp_next->filename[0] == '.')
		{
			if (tmp_prev)
			{
				tmp_prev->next = tmp_next->next;
				del_tfile(&tmp_next);
				tmp_next = tmp_prev->next;
			}
			else
			{
				*files = tmp_next->next;
				del_tfile(&tmp_next);
				tmp_next = *files;
			}
		}
		else
		{
			tmp_prev = tmp_next;
			tmp_next = tmp_next->next;
		}
	}
}