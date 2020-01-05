//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"
#include "args.h"

t_flag	chr_to_flag(char c)
{
	if (c == 'l')
		return (FLAG_l);
	if (c == 'R')
		return (FLAG_R);
	if (c == 'a')
		return (FLAG_a);
	if (c == 'r')
		return (FLAG_r);
	if (c == 't')
		return (FLAG_t);
	if (c == 'f')
		return (FLAG_f | FLAG_a);
	if (c == 'd')
		return (FLAG_d);
	return (0);
}

void			get_filenames(char **str, int arg_count, t_file **files, t_file **dirs)
{
	int 	i;
	t_file	*fl;

	i = 0;
	while (i < arg_count)
	{
		fl = new_tfile(str[i], ".");
		if (is_dir(fl))
			push_new_tfile(dirs, fl);
		else
			push_new_tfile(files, fl);
		i++;
	}
}

t_flag	parse_attr(char **str, int arg_count, t_file **files, t_file **dirs)
{
	int		i;
	int		j;
	t_flag flag;

	i = 0;
	flag = 0;
	*files = NULL;
	while (i < arg_count && str[i][0] == '-' )
	{
		j = 1;
		while (j < ft_strlen(str[i]))
		{
			if (!chr_to_flag(str[i][j]))
				return (print_error(22, &str[i][j]));
			flag |= chr_to_flag(str[i][j]);
			j++;
		}
		i++;
	}
	if (i != arg_count)
		get_filenames(str + i, arg_count - i, files, dirs); //взять все файлы
	return (flag);
}