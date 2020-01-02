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

int main (int argc, char **argv)
{
	t_file		*files;
	t_flag		flag;

	files = NULL;
	if (argc != 1)
		parse_attr(argv + 1, argc - 1, &files, &flag);

	while (files)
	{
		ft_printf("%s\n", files->filename);
		files = files->next;
	}
	/*
	if (flag & FLAG_l)
		ls_with_l(flag, files);
	 */
	return (0);
}
