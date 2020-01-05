#include "ft_ls.h"

char	*get_count_bytes(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	size_t 	i;
	char	*count_bytes;
	char	*str;

	i = ft_strlen(acr_hlnks);
	str = ft_strnew(ft_strlen(acr_hlnks) + maxlen.len_bytes + 2);
	ft_strcpy(str, acr_hlnks);
	count_bytes = ft_itoa_base(file->s_stat->st_size, 10);
	while (maxlen.len_bytes + 2 > ft_strlen(count_bytes))
	{
		str[i++] = ' ';
		maxlen.len_bytes--;
	}
	ft_strcpy(&str[i], count_bytes);
	ft_strdel(&acr_hlnks);
	ft_strdel(&count_bytes);
	return (get_end_line(file, maxlen, str));
}

char	*get_group_name(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	size_t 	i;
	char	*group_name;
	char	*str;

	i = ft_strlen(acr_hlnks);
	str = ft_strnew(ft_strlen(acr_hlnks) + maxlen.len_group + 2);
	ft_strcpy(str, acr_hlnks);
	group_name = ft_strdup(getgrgid(file->s_stat->st_gid)->gr_name);
	while (maxlen.len_group + 2 > ft_strlen(group_name))
	{
		str[i++] = ' ';
		maxlen.len_group--;
	}
	ft_strcpy(&str[i], group_name);
	ft_strdel(&acr_hlnks);
	ft_strdel(&group_name);
	return (get_count_bytes(file, maxlen, str));
}

char	*get_user_name(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	size_t 	i;
	char	*user_name;
	char	*str;

	i = ft_strlen(acr_hlnks);
	str = ft_strnew(ft_strlen(acr_hlnks) + maxlen.len_user + 1);
	ft_strcpy(str, acr_hlnks);
	user_name = ft_strdup(getpwuid(file->s_stat->st_uid)->pw_name);
	while (maxlen.len_user + 1 > ft_strlen(user_name))
	{
		str[i++] = ' ';
		maxlen.len_user--;
	}
	ft_strcpy(&str[i], user_name);
	ft_strdel(&acr_hlnks);
	ft_strdel(&user_name);
	return (get_group_name(file, maxlen, str));
}

char	*get_hard_links(t_file *file, t_maxlen maxlen, char *acrights)
{
	size_t 	i;
	char	*hardlinks;
	char	*str;

	i = ft_strlen(acrights);
	str = ft_strnew(ft_strlen(acrights) + maxlen.len_hlinks + 1);

	int a = ft_strlen(acrights) + maxlen.len_hlinks;

	ft_strcpy(str, acrights);
	hardlinks = ft_itoa_base(file->s_stat->st_nlink, 10);
	while (maxlen.len_hlinks + 1 > ft_strlen(hardlinks))
	{
		str[i++] = ' ';
		maxlen.len_hlinks--;
	}
	ft_strcpy(&str[i], hardlinks);
	ft_strdel(&acrights);
	free(hardlinks);
	return (get_user_name(file, maxlen, str));
}

char	*get_fileinfo(t_file *file, t_maxlen maxlen)
{
	char 	*acrights;

	acrights = ft_strnew(11);
	acrights[0] = get_filetype(file);
	acrights[1] = (S_IRUSR & file->s_stat->st_mode) ? 'r' : '-';
	acrights[2] = (S_IWUSR & file->s_stat->st_mode) ? 'w' : '-';
	acrights[3] = get_third_acright(file);// s-бит
	acrights[4] = (S_IRGRP & file->s_stat->st_mode) ? 'r' : '-';
	acrights[5] = (S_IWGRP & file->s_stat->st_mode) ? 'w' : '-';
	acrights[6] = get_sixth_acright(file);// s-бит
	acrights[7] = (S_IROTH & file->s_stat->st_mode) ? 'r' : '-';
	acrights[8] = (S_IWOTH & file->s_stat->st_mode) ? 'w' : '-';
	acrights[9] = get_ninth_acright(file);// t-бит
	acrights[10] = get_extended_attr(file);
	return (get_hard_links(file, maxlen, acrights));
}