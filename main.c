/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:17:38 by jwebber           #+#    #+#             */
/*   Updated: 2020/01/06 14:16:53 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "args.h"

int	main(int argc, char **argv)
{
	t_file *files;
	t_file *dirs;
	size_t flag;

	flag = 0;
	files = NULL;
	dirs = NULL;
	if (argc != 1)
		flag = parse_attr(argv + 1, argc - 1, &files, &dirs);
	if (!dirs && !files)
		dirs = new_tfile(".", ".");
	sort_by_flag(dirs, flag);
	sort_by_flag(files, flag);
	push_new_tfile(&files, dirs);
	if (flag & FLAG_L)
		ls_with_l(flag, files);
	else
		ls_without_l(flag, files);
	free_all(&files);
	return (0);
}
