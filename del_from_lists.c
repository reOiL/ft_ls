#include "ft_ls.h"

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

t_file		*del_all_files(t_file *files)
{
	t_file		*tmp_prev;
	t_file		*tmp_next;

	tmp_prev = NULL;
	tmp_next = files;
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
				files = tmp_next->next;
				del_tfile(&tmp_next);
				tmp_next = files;
			}
		}
		else
		{
			tmp_prev = tmp_next;
			tmp_next = tmp_next->next;
		}
	}
	return (files);
}