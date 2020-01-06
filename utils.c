//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"

char	*path_join(char *a, char *b)
{
	char *str_res;
	char *tmp;

	if (a && a[ft_strlen(a) - 1] == '/')
		return ft_strdup(a);
	tmp = ft_strjoin(a != NULL ? a : "", a != NULL ? "/" : "");
	str_res = ft_strjoin(tmp, b != NULL ? b : "");
	ft_strdel(&tmp);
	return (str_res);
}

void	lst_data_swap(t_file *lst1, t_file *lst2)
{
    t_file	temp;
	size_t	c_size;

	temp.s_stat = lst1->s_stat;
	temp.filename = lst1->filename;
	temp.fullpath = lst1->fullpath;
	temp.max_filename_l = lst1->max_filename_l;

    lst1->s_stat = lst2->s_stat;
    lst1->filename = lst2->filename;
    lst1->fullpath = lst2->fullpath;
    lst1->max_filename_l = lst2->max_filename_l;

    lst2->s_stat = temp.s_stat;
    lst2->filename = temp.filename;
    lst2->fullpath = temp.fullpath;
    lst2->max_filename_l = temp.max_filename_l;
}

void    sort_lst(t_file *lst, int (*cmp)(t_file *, t_file *), int asc)
{
    t_file *i;
    t_file *j;

    if (!lst)
		return ;
    i = lst;
    if (i)
	{
    while (i->next != NULL)
	{
    	j = i->next;
    	while (j != NULL)
		{
    		if (asc == 1)
			{
    			if (cmp(i, j) > 0)
					lst_data_swap(i, j);
			}
    		else
			{
    			if(cmp(i, j) < 0)
					lst_data_swap(i, j);
			}
    		j = j->next;
		}
    	i = i->next;
	}
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

int 	is_dir(t_file *file)
{
	if (!file)
		return (-1);
	return (S_ISDIR(file->s_stat->st_mode));
}

int 	is_link(t_file *file)
{
	if (!file)
		return (-1);
	return (S_ISLNK(file->s_stat->st_mode));
}

int 	is_exec(t_file *file)
{
	if (!file)
		return (-1);
	return (file->s_stat->st_mode & S_IXUSR);
}

void	sort_by_flag(t_file *lst, t_flag flag)
{
	if ((flag & FLAG_t))
		sort_lst(lst, cmp_flag_t, flag & FLAG_r ? 1 : 0);
	else if ((flag & FLAG_f) && !(flag & FLAG_d))
		sort_lst(lst, cmp_flag_f, flag & FLAG_r ? 0 : 1);
	else if (!(flag & FLAG_d))
		sort_lst(lst, cmp_flag_ascii, flag & FLAG_r ? 0 : 1);
}

void	print_file_name(t_file *file, t_flag flag)
{
	if (is_dir(file))
		ft_printf("\e[1m{cyan}");
	else if (is_link(file))
		ft_printf("\e[1m{magenta}");
	else if (is_exec(file))
		ft_printf("{red}");
	ft_printf("%-*s", *file->max_filename_l + 1, file->filename);
	ft_printf("{eoc}");
}