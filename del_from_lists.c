#include "ft_ls.h"

void		del_all_files(t_file **files)
{
	t_file		*tmp_prev;
	t_file		*tmp_next;

	tmp_prev = NULL;
	tmp_next = *files;
	while (tmp_next)
	{
		if (!S_ISDIR(tmp_next->s_stat->st_mode) || !ft_strcmp(tmp_next->filename, ".") || !ft_strcmp(tmp_next->filename, ".."))
		{
			if (tmp_prev)
			{
				tmp_prev->next = tmp_next->next;
				del_tfile(&tmp_next);
				tmp_next = tmp_prev->next ? tmp_prev->next : NULL;
			}
			else
			{
				*files = tmp_next->next ? tmp_next->next : NULL;
				del_tfile(&tmp_next);
				tmp_next = *files ? *files : NULL;
			}
		}
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