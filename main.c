/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:17:38 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/14 11:26:31 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "args.h"

void	pp(t_list *lst)
{
	t_file *ff = lst->content;
	if (!ff)
		return;
	ft_printf("%s\n", ff->filename);
}

void	pp2(t_list *lst)
{
	char *ff = lst->content;
	if (!ff)
		return;
	ft_printf("%s\n", ff);
}

void	pp3(t_list *lst)
{
	char *ff = lst->content;
	if (!ff)
		return;
	ft_printf("%s:\n", ff);
	t_list *lst2 = get_all_directory(ff);;
	ft_lstiter(lst2, pp);
	ft_lstdel(&lst2, (void (*)(void *, size_t)) free_t_file);
	ft_printf("\n");
}

int main (int argc, char **argv)
{
	t_list *lst;
	t_list *files;
	t_flag flag;

	if (argc != 1)
	{
		parse_attr(argv + 1, argc - 1, &files, &flag);
		ft_lstiter(files, pp3);
	}
	else
	{
		lst = get_all_directory(".");
		ft_lstiter(lst, pp);
		ft_lstdel(&lst, (void (*)(void *, size_t)) free_t_file);
	}
	return (0);
}
