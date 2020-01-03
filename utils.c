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

void	lst_data_swap(t_list *lst1, t_list *lst2)
{
	void	*temp;
	size_t	c_size;

	temp = lst1->content;
	c_size = lst1->content_size;
	lst1->content_size = lst2->content_size;
	lst1->content = lst2->content;
	lst2->content_size = c_size;
	lst2->content = temp;
}

void    sort_lst(t_list *lst, int (*cmp)(t_list *, t_list *), int asc)
{
    t_list *i;
    t_list *j;

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