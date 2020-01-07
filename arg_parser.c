/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:39:16 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 12:41:51 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag		chr_to_flag(char c)
{
	if (c == 'l')
		return (FLAG_L);
	if (c == 'R')
		return (FLAG_REC);
	if (c == 'a')
		return (FLAG_A);
	if (c == 'r')
		return (FLAG_R);
	if (c == 't')
		return (FLAG_T);
	if (c == 'f')
		return (FLAG_F | FLAG_A);
	if (c == 'd')
		return (FLAG_D);
	if (c == 'u')
		return (FLAG_U);
	if (c == 'U')
		return (FLAG_UBIG);
	return (0);
}

void		get_filenames(char **str, int arg_count, \
		t_file **files, t_file **dirs)
{
	int		i;
	t_file	*fl;

	i = 0;
	while (i < arg_count)
	{
		fl = new_tfile(str[i], ".");
		if (is_dir(fl))
			push_new_tfile(dirs, fl);
		else
			push_new_tfile(files, fl);
		i++;
	}
}

t_flag		parse_attr(char **str, int arg_count, t_file **files, t_file **dirs)
{
	int		i;
	size_t	j;
	t_flag	flag;

	i = 0;
	flag = 0;
	*files = NULL;
	while (i < arg_count && str[i][0] == '-' && ft_strlen(str[i]) > 1)
	{
		j = 1;
		while (j < ft_strlen(str[i]))
		{
			if (!chr_to_flag(str[i][j]))
				print_error(22, &str[i][j]);
			flag |= chr_to_flag(str[i][j]);
			j++;
		}
		i++;
	}
	if (i != arg_count)
		get_filenames(str + i, arg_count - i, files, dirs);
	return (flag);
}
