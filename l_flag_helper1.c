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
	return (blocks / 2);
}

void		sort_files(t_file **files, t_flag flag)
{
	if (!(flag & FLAG_a))
		del_all_hidden(files);
	/*
	if (flag & FLAG_t)
		sort_lst(*files, cmp_flag_a, flag & FLAG_r != 0);
	 */
}