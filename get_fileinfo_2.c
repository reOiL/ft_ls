#include "ft_ls.h"

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