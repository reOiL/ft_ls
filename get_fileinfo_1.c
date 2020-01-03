#include "ft_ls.h"

char	*get_count_bytes(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	size_t 	i;
	char	*count_bytes;
	char	*str;

	i = ft_strlen(acr_hlnks);
	str = ft_strnew(ft_strlen(acr_hlnks) + maxlen.len_bytes);
	ft_strcpy(str, acr_hlnks);
	count_bytes = ft_itoa(file->s_stat->st_size);
	while (maxlen.len_bytes + 1 > ft_strlen(count_bytes))
	{
		str[i++] = ' ';
		maxlen.len_bytes--;
	}
	ft_strcpy(&str[i], count_bytes);
	ft_strdel(&acr_hlnks);
	return (get_end_line(file, maxlen, str));
}

char	*get_group_name(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	size_t 	i;
	char	*group_name;
	char	*str;

	i = ft_strlen(acr_hlnks);
	str = ft_strnew(ft_strlen(acr_hlnks) + maxlen.len_group);
	ft_strcpy(str, acr_hlnks);
	group_name = ft_strdup(getgrgid(file->s_stat->st_gid)->gr_name);
	while (maxlen.len_group + 1 > ft_strlen(group_name))
	{
		str[i++] = ' ';
		maxlen.len_group--;
	}
	ft_strcpy(&str[i], group_name);
	ft_strdel(&acr_hlnks);
	return (get_count_bytes(file, maxlen, str));
}

char	*get_user_name(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	size_t 	i;
	char	*user_name;
	char	*str;

	i = ft_strlen(acr_hlnks);
	str = ft_strnew(ft_strlen(acr_hlnks) + maxlen.len_user);
	ft_strcpy(str, acr_hlnks);
	user_name = ft_strdup(getpwuid(file->s_stat->st_uid)->pw_name);
	while (maxlen.len_user + 1 > ft_strlen(user_name))
	{
		str[i++] = ' ';
		maxlen.len_user--;
	}
	ft_strcpy(&str[i], user_name);
	ft_strdel(&acr_hlnks);
	return (get_group_name(file, maxlen, str));
}

char	*get_hard_links(t_file *file, t_maxlen maxlen, char *acrights)
{
	size_t 	i;
	char	*hardlinks;
	char	*str;

	i = ft_strlen(acrights);
	str = ft_strnew(ft_strlen(acrights) + maxlen.len_hlinks);
	ft_strcpy(str, acrights);
	hardlinks = ft_itoa(file->s_stat->st_nlink);
	while (maxlen.len_hlinks + 1 > ft_strlen(hardlinks))
	{
		str[i++] = ' ';
		maxlen.len_hlinks--;
	}
	ft_strcpy(&str[i], hardlinks);
	ft_strdel(&acrights);
	//free(hardlinks); //TODO почему дабл фри в этом месте???
	return (get_user_name(file, maxlen, str));
}

char	*get_fileinfo(t_file *file, t_maxlen maxlen)
{
	char 	*acrights;

	acrights = ft_strnew(10);// ДОБАВИТЬ ПРОВЕРКУ И ERRNO
	acrights[0] = (S_IFDIR & file->s_stat->st_mode) ? 'd' : '-'; // ПОТОМ ИЗМЕНИТЬ НА ОТДЕЛЬНУЮ ФУНКЦИЮ
	acrights[1] = (S_IRUSR & file->s_stat->st_mode) ? 'r' : '-';
	acrights[2] = (S_IWUSR & file->s_stat->st_mode) ? 'w' : '-';
	acrights[3] = (S_IXUSR & file->s_stat->st_mode) ? 'x' : '-';
	acrights[4] = (S_IRGRP & file->s_stat->st_mode) ? 'r' : '-';
	acrights[5] = (S_IWGRP & file->s_stat->st_mode) ? 'w' : '-';
	acrights[6] = (S_IXGRP & file->s_stat->st_mode) ? 'x' : '-';
	acrights[7] = (S_IROTH & file->s_stat->st_mode) ? 'r' : '-';
	acrights[8] = (S_IWOTH & file->s_stat->st_mode) ? 'w' : '-';
	acrights[9] = (S_IXOTH & file->s_stat->st_mode) ? 'x' : '-';
	return (get_hard_links(file, maxlen, acrights));
}

