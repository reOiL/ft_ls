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

t_maxlen	get_max_lengths(DIR *dir)
{
	t_maxlen		max_len;
	struct dirent	*dp;
	struct stat		stats;

	max_len = initialize_maxlen();
	while (dp = readdir(dir))
	{
		//TODO разобраться почему он берет хуйню
		/*
		stat(dp->d_name, &stats);
		if (max_len.len_hlinks < count_digits(stats.st_nlink, 10))
			max_len.len_hlinks = count_digits(stats.st_nlink, 10);
		if (max_len.len_group < ft_strlen(getgrgid(stats.st_gid)->gr_name))
			max_len.len_group = ft_strlen(getgrgid(stats.st_gid)->gr_name);
		if (max_len.len_user < ft_strlen(getpwuid(stats.st_uid)->pw_name))
			max_len.len_user = ft_strlen(getpwuid(stats.st_uid)->pw_name);
		if (max_len.len_bytes < count_digits(stats.st_size, 10))
			max_len.len_bytes = count_digits(stats.st_size, 10);
		 */
	}
	return (max_len);
}

char	*get_hard_links(struct dirent *dp, struct stat *stats, char *acrights)
{
	char	*str;

}

char	*get_access_rights(struct dirent *dp, struct stat stats)
{
	char 	*acrights;

	acrights = ft_strnew(11);// ДОБАВИТЬ ПРОВЕРКУ И ERRNO
	acrights[0] = (S_IFDIR & stats.st_mode) ? 'd' : '-'; // ПОТОМ ИЗМЕНИТЬ НА ОТДЕЛЬНУЮ ФУНКЦИЮ
	acrights[1] = (S_IRUSR & stats.st_mode) ? 'r' : '-';
	acrights[2] = (S_IWUSR & stats.st_mode) ? 'w' : '-';
	acrights[3] = (S_IXUSR & stats.st_mode) ? 'x' : '-';
	acrights[4] = (S_IRGRP & stats.st_mode) ? 'r' : '-';
	acrights[5] = (S_IWGRP & stats.st_mode) ? 'w' : '-';
	acrights[6] = (S_IXGRP & stats.st_mode) ? 'x' : '-';
	acrights[7] = (S_IROTH & stats.st_mode) ? 'r' : '-';
	acrights[8] = (S_IWOTH & stats.st_mode) ? 'w' : '-';
	acrights[9] = (S_IXOTH & stats.st_mode) ? 'x' : '-';
	acrights[10] = ' ';
	ft_printf("%s", acrights);
	ft_printf("%s\n", dp->d_name);
	return (acrights); //get_hard_links(dp, stats, acrights));
}
