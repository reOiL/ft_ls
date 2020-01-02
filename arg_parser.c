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

/*
 * TODO: return false if failed parse flag!!!
 */
void	parse_attr(char **str, int arg_count, t_list **lst, t_flag *flag)
{
	int		i;
	t_flag	tmp;

	if (str == NULL || lst == NULL || flag == NULL)
		return;
	*flag = 0;
	*lst = NULL;
	i = 0;
	if (str[0][0] == '-')
	{
		i++;
		while (i < ft_strlen(str[0]))
		{
			tmp = chr_to_flag(str[0][i]);
		}
	}
	i = 0;
	while (i < arg_count)
	{
		//if (str[i][0] == '-' && (tmp = str_to_flag(str[i])))
		//	*flag |= tmp;
		//else
		//	ft_lstadd(lst, ft_lstnew(str[i], ft_strlen(str[i])));
		i++;
	}
}