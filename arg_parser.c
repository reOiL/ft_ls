//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"
#include "args.h"

t_flag 	chr_to_flag(char c)
{
	if (c == 'l')
		return FLAG_l;
	if (c == 'R')
		return FLAG_R;
	if (c == 'a')
		return FLAG_a;
	if (c == 'r')
		return FLAG_r;
	if (c == 't')
		return FLAG_t;
	return (0);
}

t_file	*get_filenames(char **str, int arg_count, int i)
{
	t_file	*files;

	files = NULL;
	while (i < arg_count)
	{
		add_new_dir(&files, str[i]);
		i++;
	}
	return (files);
}

int		parse_attr(char **str, int arg_count, t_file **files, t_flag *flag)
{
	int		i;
	int		j;

	i = 0;
	*flag = 0;
	*files = NULL;
	while (str[i][0] == '-' && i < arg_count)
	{
		j = 1;
		while (j < ft_strlen(str[i]))
		{
			if (!chr_to_flag(str[i][j]))
				return (print_error(22, str[i]));
			if (!(*flag & chr_to_flag(str[i][j])))
				*flag += chr_to_flag(str[i][j]);
			j++;
		}
		i++;
	}
	if (i != arg_count)
		*files = get_filenames(str, arg_count, i); //взять все файлы
}