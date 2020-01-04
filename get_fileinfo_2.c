#include "ft_ls.h"

char	*add_linkway(t_file *file, char *str)
{
	char			*str_link;
	char 			*full_str;
	char			*end_str;
	char 			*end_and_link;

	str_link = ft_strnew(1000);
	readlink(file->fullpath, str_link, 1000);
	end_str = ft_strdup(" -> ");
	end_and_link = ft_strjoin(end_str, str_link);
	ft_strdel(&end_str);
	ft_strdel(&str_link);
	full_str = ft_strjoin(str, end_and_link);
	ft_strdel(&str);
	ft_strdel(&end_and_link);
	return (full_str);
}

char 	*get_end_line(t_file *file, t_maxlen maxlen, char *acr_hlnks)
{
	char	*time_stamp;
	char	*str;

	time_stamp = ctime(&file->s_stat->st_mtimespec.tv_sec);
	str = ft_strnew(ft_strlen(acr_hlnks) + 1 + ft_strlen(time_stamp) + ft_strlen(file->filename));
	ft_strcpy(str, acr_hlnks);
	str[ft_strlen(acr_hlnks)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + 1], time_stamp);
	str[ft_strlen(acr_hlnks) + ft_strlen(time_stamp)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + ft_strlen(time_stamp) + 1], file->filename);
	ft_strdel(&acr_hlnks);
	if (S_ISLNK(file->s_stat->st_mode))
		str = add_linkway(file, str);
	return (str);
}