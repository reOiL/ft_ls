#include "ft_ls.h"

void	del_tfile(t_file **files)
{
	if ((*files)->s_stat)
		ft_memdel((void **)&(*files)->s_stat);
	if ((*files)->filename)
		ft_strdel(&(*files)->filename);
	if ((*files)->fullpath)
		ft_strdel(&(*files)->fullpath);
	if ((*files)->len)
	{
		(*(*files)->len)--;
		if (*(*files)->len == 0)
		{
			ft_memdel((void **)&(*files)->len);
			ft_memdel((void **)&(*files)->max_filename_l);
		}
	}
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
	item->len = NULL;
	item->max_filename_l = NULL;
	return (item);
}

void		push_new_tfile(t_file **files, t_file *new_files)
{
	if (*files == NULL)
	{
		*files = new_files;
		//if ((*files)->len == NULL)
		//	(*files)->len = ft_memalloc(sizeof(size_t));
		//if ((*files)->max_filename_l)
		//	(*files)->max_filename_l = ft_memalloc(sizeof(size_t));
		//(*(*files)->len) += 1;
		return ;
	}
	push_new_tfile(&(*files)->next, new_files);
}

void		add_new_tfile(t_file **files, char *filename, char *path)
{
	t_file		*tmp_prev;
	t_file		*tmp_next;
	size_t 		prev_file_len;

	tmp_prev = NULL;
	tmp_next = *files;
	while (tmp_next)
	{
		tmp_prev = tmp_next;
		tmp_next = tmp_next->next ? tmp_next->next : NULL;
	}
	if (tmp_prev)
	{
		tmp_prev->next = new_tfile(filename, path);
		prev_file_len = ft_strlen(tmp_prev->next->filename);
		tmp_prev->next->max_filename_l = tmp_prev->max_filename_l;
		tmp_prev->next->len = tmp_prev->len;
		*tmp_prev->next->len += 1;
		*tmp_prev->max_filename_l = *tmp_prev->next->max_filename_l > prev_file_len ?
									*tmp_prev->next->max_filename_l : prev_file_len;
	}
	else
	{
		*files = new_tfile(filename, path);
		(*files)->max_filename_l = ft_memalloc(sizeof(size_t));
		(*files)->len = ft_memalloc(sizeof(size_t));
		*(*files)->max_filename_l = ft_strlen((*files)->filename);
		*(*files)->len = 1;
	}
}