//
// Created by Johnny Webber on 02/01/2020.
//

#ifndef FT_LS_ARGS_H
# define FT_LS_ARGS_H

#include "ft_ls.h"

//arg_parser
t_flag			chr_to_flag(char c);
void			get_filenames(char **str, int arg_count, t_file **files, t_file **dirs);
t_flag			parse_attr(char **str, int arg_count, t_file **files, t_file **dirs);

//l_flag.c
int				print_fileinfo_l(t_file *subfiles, t_flag flag, char *path);
int				print_files_links(char *filename, t_flag flag, char *path);
int				print_dirfiles(char *dirname, t_flag flag, char *path);
void			print_files_l(t_flag flag, t_file *arg_dirs, int only_one);
void			ls_with_l(t_flag flag, t_file *arg_dirs);

#endif
