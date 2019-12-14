/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 08:49:20 by jwebber           #+#    #+#             */
/*   Updated: 2019/11/14 10:04:12 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# define BUFF_SIZE 9999

typedef struct s_file	t_file;

struct	s_file
{
	int		fd;
	char	*fdata;
};

int		get_next_line(const int fd, char **line);

#endif
