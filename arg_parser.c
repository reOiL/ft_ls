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
	return (0);
}

t_flag	str_to_flag(char *str)
{
	t_flag flg;
	t_flag tmp;

	flg = 0;
	if (*str != '-')
		return 0;
	str++;
	while (*str)
	{
		if (!(tmp = chr_to_flag(*str)))
			return 0;
		flg |= tmp;
		str++;
	}
	return (flg);
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
	tmp = 1;
	while (i < arg_count)
	{
		if (tmp != 0)
			tmp = str_to_flag(str[i]);
		if (tmp != 0)
			*flag |= tmp;
		else
			ft_lstadd(lst, ft_lstnew(str[i], ft_strlen(str[i]) + 1));
		i++;
	}
}