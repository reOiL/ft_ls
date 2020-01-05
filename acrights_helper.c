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

char 	get_third_acright(t_file *file)
{
	if (S_ISUID & file->s_stat->st_mode)
		return ('s');
	if (S_IXUSR & file->s_stat->st_mode)
		return ('x');
	return ('-');
}

char 	get_sixth_acright(t_file *file)
{
	if (S_ISGID & file->s_stat->st_mode)
		return ('s');
	if (S_IXGRP & file->s_stat->st_mode)
		return ('x');
	return ('-');
}

char 	get_ninth_acright(t_file *file)
{
	if (S_ISVTX & file->s_stat->st_mode)
		return ('t');
	if (S_IXOTH & file->s_stat->st_mode)
		return ('x');
	return ('-');
}

char 	get_extended_attr(t_file *file)
{
	char 	*acl;

	acl = ft_strnew(100);
	if (listxattr(file->fullpath, acl, 100, 0) && !S_ISLNK(file->s_stat->st_mode))
		return ('@');
	return (' ');
}