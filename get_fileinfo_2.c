#include "ft_ls.h"

char	get_filetype(t_file *file)
{
	if (S_ISLNK(file->s_stat->st_mode))
		return ('l');
	if (S_ISDIR(file->s_stat->st_mode))
		return ('d');
	if (S_ISSOCK(file->s_stat->st_mode))
		return ('s');
	if (S_ISBLK(file->s_stat->st_mode))
		return ('b');
	if (S_ISCHR(file->s_stat->st_mode))
		return ('c');
	if (S_ISFIFO(file->s_stat->st_mode))
		return ('p');
	return ('-');
}

char 	*get_end_line(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	char	*time_stamp;
	char	*str;

	time_stamp = ctime(&file->s_stat->st_mtim.tv_sec);
	str = ft_strnew(ft_strlen(acr_hlnks) + 1 + ft_strlen(time_stamp) + ft_strlen(file->filename));
	ft_strcpy(str, acr_hlnks);
	str[ft_strlen(acr_hlnks)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + 1], time_stamp);
	str[ft_strlen(acr_hlnks) + ft_strlen(time_stamp)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + ft_strlen(time_stamp) + 1], file->filename);
	ft_strdel(&acr_hlnks);
	return (str);
}