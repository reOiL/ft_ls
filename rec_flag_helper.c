/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_flag_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:37:06 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 14:37:38 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "args.h"

t_file		*go_rec(t_file **subfiles, t_flag flag, char *path, int only_one)
{
	t_file	*tmp;

	tmp = *subfiles;
	if (!(flag & FLAG_REC))
		return (tmp);
	if (flag & FLAG_REC)
	{
		del_all_files(subfiles);
		tmp = *subfiles;
		while (*subfiles)
		{
			if (is_dir(*subfiles))
			{
				ft_putchar('\n');
				print_dirfiles((*subfiles)->filename, flag, \
						path_join(path, (*subfiles)->filename), 0);
			}
			*subfiles = (*subfiles)->next;
		}
	}
	return (tmp);
}
