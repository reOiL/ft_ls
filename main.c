/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:17:38 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/14 11:26:31 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	pp(t_list *lst)
{
	t_file *ff = lst->content;
	if (!ff)
		return;
	ft_printf("%s\n", ff->filename);
}

int main (int argc, char **argv)
{
	t_list *lst;

	lst = get_all_directory("..");
	ft_lstiter(lst, pp);
	ft_lstdel(&lst, (void (*)(void *, size_t)) free_t_file);
	return (0);
}
