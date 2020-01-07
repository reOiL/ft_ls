/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acrights_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:31:56 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/06 15:06:44 by eblackbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/acl.h>

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

char	get_third_acright(t_file *file)
{
	if (S_ISUID & file->s_stat->st_mode)
		return ('s');
	if (S_IXUSR & file->s_stat->st_mode)
		return ('x');
	return ('-');
}

char	get_sixth_acright(t_file *file)
{
	if (S_ISGID & file->s_stat->st_mode)
		return ('s');
	if (S_IXGRP & file->s_stat->st_mode)
		return ('x');
	return ('-');
}

char	get_ninth_acright(t_file *file)
{
	if (S_ISVTX & file->s_stat->st_mode)
		return ('t');
	if (S_IXOTH & file->s_stat->st_mode)
		return ('x');
	return ('-');
}

char 	get_acl(t_file *file)
{
	acl_t	acl;
	char 	a;

	if (listxattr(file->fullpath, &a, 1, XATTR_NOFOLLOW) < 0 && errno != EACCES)
		return '@';
	acl = acl_get_file(file->fullpath, ACL_TYPE_EXTENDED);
	if (acl)
	{
		acl_free(acl);
		return '+';
	}
	return ' ';
}