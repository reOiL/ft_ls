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
	char *ret;

	ret = ft_strnew(14);
	if (flag & FLAG_UBIG)
		timestamp = ctime(&file->s_stat->st_ctimespec.tv_sec);
	else if (flag & FLAG_U)
		timestamp = ctime(&file->s_stat->st_atimespec.tv_sec);
	else
		timestamp = ctime(&file->s_stat->st_mtimespec.tv_sec);
	if (file->s_stat->st_mtimespec.tv_sec < time(NULL) - 15768000)
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

char	*get_end_line(t_file *file, char *acr_hlnks, t_flag flag)
{
	char	*time_stamp;
	char	*str;

	time_stamp = get_timestamp(file, flag);
	str = ft_strnew(ft_strlen(acr_hlnks) + 15 + ft_strlen(file->filename));
	ft_strcpy(str, acr_hlnks);
	str[ft_strlen(acr_hlnks)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + 1], time_stamp);
	str[ft_strlen(acr_hlnks) + ft_strlen(time_stamp)] = ' ';
	ft_strcpy(&str[ft_strlen(acr_hlnks) + \
			ft_strlen(time_stamp) + 1], file->filename);
	ft_strdel(&acr_hlnks);
	ft_strdel(&time_stamp);
	if (S_ISLNK(file->s_stat->st_mode))
		str = add_linkway(file, str);
	return (str);
}