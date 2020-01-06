/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:17:17 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 14:17:58 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_tfile(t_file **files)
{
	if ((*files)->s_stat)
		free((*files)->s_stat);
	if ((*files)->filename)
		ft_strdel(&(*files)->filename);
	if ((*files)->fullpath)
		ft_strdel(&(*files)->fullpath);
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
	item->fullpath = ft_strcmp(path, ".") ? \
					path_join(path, filename) : ft_strdup(filename);
	lstat(item->fullpath, item->s_stat);
	return (item);
}

void		push_new_tfile(t_file **files, t_file *new_files)
{
	if (*files == NULL)
	{
		*files = new_files;
		return ;
	}
	push_new_tfile(&(*files)->next, new_files);
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
		tmp_next = tmp_next->next ? tmp_next->next : NULL;
	}
	if (tmp_prev)
		tmp_prev->next = new_tfile(filename, path);
	else
		*files = new_tfile(filename, path);
}
