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
#include "args.h"

int main (int argc, char **argv)
{
	t_file		*files;
	size_t		flag;

	flag = 0;
	files = NULL;
	if (argc != 1)
		parse_attr(argv + 1, argc - 1, &files, &flag);
	else
		files = new_tfile(".");
	if (flag & FLAG_l)
		ls_with_l(flag, files);
	else
		/* ЭТО ТЕБЕ ГРИШ
		ls_without_l(flag, files);
		 */
	//free все что было здесь
	return (0);
}
