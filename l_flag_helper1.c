/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag_helper1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:37:48 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 14:38:16 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_maxlen	initialize_maxlen(void)
{
	t_maxlen	n;

	n.len_hlinks = 0;
	n.len_group = 0;
	n.len_user = 0;
	n.len_bytes = 0;
	return (n);
}

t_maxlen	get_max_lengths(t_file *files)
{
	t_maxlen		max_len;
	struct stat		*stats;

	max_len = initialize_maxlen();
	while (files)
	{
		stats = files->s_stat;
		if (max_len.len_hlinks < count_digits(stats->st_nlink, 10))
			max_len.len_hlinks = count_digits(stats->st_nlink, 10);
		if (max_len.len_group < ft_strlen(getgrgid(stats->st_gid)->gr_name))
			max_len.len_group = ft_strlen(getgrgid(stats->st_gid)->gr_name);
		if (max_len.len_user < ft_strlen(getpwuid(stats->st_uid)->pw_name))
			max_len.len_user = ft_strlen(getpwuid(stats->st_uid)->pw_name);
		if (max_len.len_bytes < count_digits(stats->st_size, 10))
			max_len.len_bytes = count_digits(stats->st_size, 10);
		files = files->next;
	}
	return (max_len);
}

size_t		get_blocks(t_file *files)
{
	size_t		blocks;

	blocks = 0;
	while (files)
	{
		blocks += files->s_stat->st_blocks;
		files = files->next;
	}
	return (blocks);
}

void		sort_files(t_file **files, t_flag flag)
{
	if ((flag & FLAG_T))
		sort_lst(*files, cmp_flag_t, flag & FLAG_R ? 1 : 0);
	else
		sort_lst(*files, cmp_flag_ascii, flag & FLAG_R ? 0 : 1);
}
