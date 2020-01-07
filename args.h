/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:42:47 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/07 10:54:52 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_ARGS_H
# define FT_LS_ARGS_H

# include "ft_ls.h"

/*
** arg_parser.c
*/
t_flag			chr_to_flag(char c);
void			get_filenames(char **str, int arg_count, \
		t_file **files, t_file **dirs);
t_flag			parse_attr(char **str, int arg_count, \
		t_file **files, t_file **dirs);

/*
** ls_with_l.c
*/
void			print_fileinfo_l(t_file **subfiles, t_flag flag);
void			print_files_links(char *filename, t_flag flag, char *path);
int				print_dirfiles(char *dirname, t_flag flag, char \
				*path, int only_one);
void			print_files_l(t_flag flag, t_file *arg_dirs, int only_one);
void			ls_with_l(t_flag flag, t_file *arg_dirs);

/*
** rec_flag_helper.c
*/
t_file			*go_rec(t_file **subfiles, t_flag flag, char *path);

#endif
