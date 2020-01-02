//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"


char	*path_join(char *a, char *b)
{
	char *str_res;
	char *tmp;

	tmp = ft_strjoin(a, "/");
	str_res = ft_strjoin(tmp, b);
	ft_strdel(&tmp);
	return (str_res);
}