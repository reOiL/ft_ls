/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_from_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:47:38 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 12:48:37 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		del_one_file(t_file **files, t_file **prev, t_file **next)
{
	if (*prev)
	{
		(*prev)->next = (*next)->next;
		del_tfile(next);
		*next = (*prev)->next ? (*prev)->next : NULL;
	}
	else
	{
		*files = (*next)->next ? (*next)->next : NULL;
		del_tfile(next);
		*next = *files ? *files : NULL;
	}
}

void		del_all_files(t_file **files)
{
	t_file		*tmp_prev;
	t_file		*tmp_next;

	tmp_prev = NULL;
	tmp_next = *files;
	while (tmp_next)
	{
		if (!S_ISDIR(tmp_next->s_stat->st_mode) || \
		!ft_strcmp(tmp_next->filename, ".") || \
		!ft_strcmp(tmp_next->filename, ".."))
			del_one_file(files, &tmp_prev, &tmp_next);
		else
		{
			tmp_prev = tmp_next;
			tmp_next = tmp_next->next;
		}
	}
}

void		free_all(t_file **files)
{
	t_file	*tmp;

	while (files && *files)
	{
		tmp = (*files)->next;
		del_tfile(files);
		*files = tmp;
	}
}
