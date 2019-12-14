/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colored.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:49:13 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/10 17:50:07 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		code_to_color(const char *code)
{
	int		ret;

	ret = 0;
	if (!ft_strncmp("{red}", code, ft_strlen("{red}")) && (ret = 1))
		ft_putstr("\e[31m");
	else if (!ft_strncmp("{green}", code, ft_strlen("{green}")) && (ret = 1))
		ft_putstr("\e[32m");
	else if (!ft_strncmp("{yellow}", code, ft_strlen("{yellow}"))
				&& (ret = 1))
		ft_putstr("\e[33m");
	else if (!ft_strncmp("{blue}", code, ft_strlen("{blue}")) && (ret = 1))
		ft_putstr("\e[34m");
	else if (!ft_strncmp("{magenta}", code, ft_strlen("{magenta}"))
				&& (ret = 1))
		ft_putstr("\e[35m");
	else if (!ft_strncmp("{cyan}", code, ft_strlen("{cyan}")) && (ret = 1))
		ft_putstr("\e[36m");
	else if (!ft_strncmp("{white}", code, ft_strlen("{white}")) && (ret = 1))
		ft_putstr("\e[97m");
	else if (!ft_strncmp("{eoc}", code, ft_strlen("{eoc}")) && (ret = 1))
		ft_putstr("\e[0m");
	return (ret);
}

size_t	colored(const char *str)
{
	char	*end_bracket;

	end_bracket = NULL;
	if (str == NULL || *str != '{')
		return (0);
	end_bracket = ft_strchr(str, '}');
	if (end_bracket == NULL)
		return (0);
	if (!code_to_color(str))
		return (0);
	return (end_bracket - str + 1);
}
