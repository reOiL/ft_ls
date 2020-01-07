/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fileinfo_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:15:04 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/07 10:51:44 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add_linkway(t_file *file, char *str)
{
	char			*str_link;
	char			*full_str;
	char			*end_str;
	char			*end_and_link;

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

char 	*get_timestamp(t_file *file, t_flag flag)
{
	char *timestamp;
	struct timespec spec;
	char *ret;

	ret = ft_strnew(14);
	if (flag & FLAG_UBIG)
		spec = file->s_stat->st_birthtimespec;
	else if (flag & FLAG_U)
		spec = file->s_stat->st_atimespec;
	else
		spec = file->s_stat->st_mtimespec;
	timestamp = ctime(&spec.tv_sec);
	if (spec.tv_sec < time(NULL) - 15768000)
	{
		ft_strncpy(ret, &timestamp[4], 7);
		ft_strncpy(&ret[7], &timestamp[19], 6);
	}
	else
	{
		ft_strncpy(ret, &timestamp[4], 13);
	}
	return (ret);
}

char	*colored_name(t_file *file, t_flag flag)
{
	if (is_dir(file) && flag & FLAG_G)
		return ("\e[1m\e[36m");
	else if (is_link(file) && flag & FLAG_G)
		return ("\e[1m\e[35m");
	else if (is_exec(file) && flag & FLAG_G)
		return ("31m");
	return ("");
}

char	*get_end_line(t_file *file, char *acr_hlnks, t_flag flag)
{
	char	*time_stamp;
	char	*str;
	char 	*color;

	time_stamp = get_timestamp(file, flag);
	color = colored_name(file, flag);
	str = ft_strnew(ft_strlen(acr_hlnks) + 15 + ft_strlen(file->filename)
			+ ft_strlen(color) + 4);
	ft_strcpy(str, acr_hlnks);
	str[ft_strlen(acr_hlnks)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + 1], time_stamp);
	str[ft_strlen(acr_hlnks) + ft_strlen(time_stamp)] = ' ';
	ft_strcpy(&str[ft_strlen(str)], color);
	ft_strcpy(&str[ft_strlen(str)], file->filename);
	if (flag & FLAG_G)
		ft_strcpy(&str[ft_strlen(str)], "\e[0m");
	ft_strdel(&acr_hlnks);
	ft_strdel(&time_stamp);
	if (S_ISLNK(file->s_stat->st_mode))
		str = add_linkway(file, str);
	return (str);
}