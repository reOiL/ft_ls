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

void		del_all_files(t_file **files)
{
	if (*files == NULL)
		return ;
	del_all_files(&(*files)->next);
	del_tfile(files);
}

void		free_all(t_file **files)
{
	t_file	*tmp;

	while (*files)
	{
		tmp = (*files)->next;
		del_tfile(files);
		*files = tmp;
	}
}