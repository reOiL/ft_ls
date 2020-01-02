#include "ft_ls.h"

t_file	*new_tfile(char *filename)
{
	t_file	*item;

	item = (t_file*)malloc(sizeof(t_file));
	if (item == NULL)
		return (NULL);
	item->next = NULL;
	item->filename = ft_strdup(filename);
	item->s_stat = (struct stat*)malloc(sizeof(struct stat));
	stat(filename, item->s_stat);
	return (item);
}

void	add_new_dir(t_file **files, char *filename)
{
	t_file		*tmp_prev;
	t_file		*tmp_next;
	struct stat	stats;

	tmp_prev = NULL;
	tmp_next = *files;
	stat(filename, &stats);
	//добавить проверку, существует ли файл либо это ссылка. Наверно придется сортировать по st_mode.
	while (tmp_next && ft_strcmp(tmp_next->filename, filename) < 0 && !(S_ISDIR(stats.st_mode) && !S_ISDIR(tmp_next->s_stat->st_mode)))
	{
		tmp_prev = tmp_next;
		tmp_next = tmp_next->next;
	}
	if (tmp_prev)
	{
		tmp_prev->next = new_tfile(filename);
		tmp_prev->next->next = tmp_next;
	}
	else
	{
		*files = new_tfile(filename);
		(*files)->next = tmp_next;
	}
}