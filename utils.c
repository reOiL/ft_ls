//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"

char	*path_join(char *a, char *b)
{
	char *str_res;
	char *tmp;

	tmp = ft_strjoin(a, "/");
	str_res = ft_strjoin(tmp, b);
	ft_strdel(&tmp);
	return (str_res);
}

void	lst_data_swap(t_file *lst1, t_file *lst2)
{
    t_file	temp;
	size_t	c_size;

	temp.s_stat = lst1->s_stat;
	temp.filename = lst1->filename;

    lst1->s_stat = lst2->s_stat;
    lst1->filename = lst2->filename;

    lst2->s_stat = temp.s_stat;
    lst2->filename = temp.filename;
}

void    sort_lst(t_file *lst, int (*cmp)(t_file *, t_file *), int asc)
{
    t_file *i;
    t_file *j;

    i = lst;
    while (i->next != NULL)
	{
    	j = i->next;
    	while (j != NULL)
		{
    		if (asc == 1 && cmp(i, j) > 0)
				lst_data_swap(i, j);
    		else if (cmp(i, j) < 0)
				lst_data_swap(i, j);
    		j = j->next;
		}
    	i = i->next;
	}
}

void	ft_list_reverse(t_file **begin_list)
{
    t_file	*p;
    t_file	*n;

    p = 0;
    while (*begin_list)
    {
        n = (*begin_list)->next;
        (*begin_list)->next = p;
        p = (*begin_list);
        if (n == 0)
            return ;
        (*begin_list) = n;
    }
}

char    *get_link_path(char *path)
{
    char *mem;

    mem = ft_strnew(1024);
    if (readlink(path, mem, 1024) < 0)
        return (NULL);
    return (mem);
}