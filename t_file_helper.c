#include "ft_ls.h"

t_file	*new_tfile(char *filename)
{
	t_file	*item;

	item = (t_file*)malloc(sizeof(t_file));
	if (item == NULL)
		return (NULL);
	item->next = NULL;
	item->filename = ft_strdup(filename);
	stat(filename, &item->s_stat);
	return (item);
}

void	add_new_dir(t_file **files, char *filename)
{
	t_file	*tmp_prev;
	t_file	*tmp_next;

	tmp_prev = NULL;
	tmp_next = *files;
	while (tmp_next && ft_strcmp(tmp_next->filename, filename) < 0)
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