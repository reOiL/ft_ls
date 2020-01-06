/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:04:09 by jwebber           #+#    #+#             */
/*   Updated: 2020/01/06 13:08:56 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_join(char *a, char *b)
{
	char *str_res;
	char *tmp;

	if (a && a[ft_strlen(a) - 1] == '/')
		return (ft_strdup(a));
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
	lst1->s_stat = lst2->s_stat;
	lst1->filename = lst2->filename;
	lst1->fullpath = lst2->fullpath;
	lst2->s_stat = temp.s_stat;
	lst2->filename = temp.filename;
	lst2->fullpath = temp.fullpath;
}

void	sort_lst(t_file *lst, int (*cmp)(t_file *, t_file *), int asc)
{
	t_file *i;
	t_file *j;

	if (!lst)
		return ;
	i = lst;
	while (i && i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (asc == 1 ? cmp(i, j) > 0 : cmp(i, j) < 0)
				lst_data_swap(i, j);
			j = j->next;
		}
		i = i->next;
	}
}
