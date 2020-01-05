//
// Created by Владелец on 03.01.2020.
//

#include "ft_ls.h"

int cmp_flag_t(t_file *f1, t_file *f2)
{
    if (f1->s_stat->st_mtimespec.tv_sec > f2->s_stat->st_mtimespec.tv_sec)
		return (1);
    if (f1->s_stat->st_mtimespec.tv_sec < f2->s_stat->st_mtimespec.tv_sec)
        return (-1);
    return (-cmp_flag_ascii(f1, f2));
}

int cmp_flag_ascii(t_file *f1, t_file *f2)
{
	return (strcmp(f1->filename, f2->filename));
}

int cmp_file_type(t_file *f1, t_file *f2)
{
	int a;
	int b;

	a = is_dir(f1);
	b = is_dir(f2);
	if (a && !b)
		return (1);
	if (!a && b)
		return (1);
	return (0);
}

int cmp_file_type_ascii(t_file *f1, t_file *f2)
{
	int a;
	int b;

	a = is_dir(f1);
	b = is_dir(f2);
	if (a && !b)
		return (1);
	if (!a && b)
		return (1);
	return (0);
}