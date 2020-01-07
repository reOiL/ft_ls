/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblackbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:50:39 by eblackbu          #+#    #+#             */
/*   Updated: 2020/01/07 10:56:09 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>

# define FLAG_L		0x1
# define FLAG_REC	(FLAG_L << 1)
# define FLAG_A		(FLAG_L << 2)
# define FLAG_R		(FLAG_L << 3)
# define FLAG_T		(FLAG_L << 4)
# define FLAG_F		(FLAG_L << 5)
# define FLAG_D		(FLAG_L << 6)
# define FLAG_G		(FLAG_L << 7)
# define FLAG_U		(FLAG_L << 8)
# define FLAG_UBIG	(FLAG_L << 9)

typedef size_t			t_flag;
typedef struct dirent	t_dirent;

typedef struct		s_file
{
	char			*filename;
	char			*fullpath;
	struct stat		*s_stat;
	struct s_file	*next;
}					t_file;

typedef struct		s_maxlen
{
	unsigned int	len_hlinks;
	unsigned int	len_group;
	unsigned int	len_user;
	unsigned int	len_bytes;
}					t_maxlen;

/*
** acrights_helper.c
*/
char				get_filetype(t_file *file);
char				get_third_acright(t_file *file);
char				get_sixth_acright(t_file *file);
char				get_ninth_acright(t_file *file);
char				get_acl(t_file *file);

/*
** comparators.c
*/
int					cmp_flag_t(t_file *f1, t_file *f2);
int					cmp_flag_ascii(t_file *f1, t_file *f2);
int					cmp_flag_f(t_file *f1, t_file *f2);

/*
** comparators_2.c
*/
int					cmp_flag_u(t_file *f1, t_file *f2);
int					cmp_flag_ubig(t_file *f1, t_file *f2);

/*
** del_from_lists
*/
void				del_all_files(t_file **files);
void				free_all(t_file **files);

/*
** errors.c
*/
int					print_error(int code, char *str);

/*
** get_fileinfo_1.c
*/
char				*get_count_bytes(t_file *file, t_maxlen maxlen,
										char *acr_hlnks, t_flag flag);
char				*get_group_name(t_file *file, t_maxlen maxlen,
									char *acr_hlnks, t_flag flag);
char				*get_user_name(t_file *file, t_maxlen maxlen,
									char *acr_hlnks, t_flag flag);
char				*get_hard_links(t_file *file, t_maxlen maxlen,
									char *acrights, int flag);
char				*get_fileinfo(t_file *file, t_maxlen maxlen, t_flag flag);

/*
** get_fileinfo_2.c
*/
char				*add_linkway(t_file *file, char *str);
char				*get_end_line(t_file *file, char *acr_hlnks, t_flag flag);
void				print_dir(t_flag flag, t_file *file, int is_many,
								int is_first);

/*
** l_flag_helper1.c
*/
t_maxlen			initialize_maxlen(void);
t_maxlen			get_max_lengths_files(t_file *files);
t_maxlen			get_max_lengths(t_file *files);
size_t				get_blocks(t_file *files);

/*
** t_file_helper.c
*/
void				del_tfile(t_file **files);
t_file				*new_tfile(char *filename, char *path);
void				push_new_tfile(t_file **files, t_file *new_files);
void				add_new_tfile(t_file **files, char *filename, char *path);

/*
** utils.c
*/
char				*path_join(char *a, char *b);
void				lst_data_swap(t_file *lst1, t_file *lst2);
void				sort_lst(t_file *lst, int \
		(*cmp)(t_file *, t_file *), int asc);
void				sort_by_flag(t_file *lst, t_flag flag);
int					is_spec_dir(t_file *file);
int					is_dir(t_file *file);
int					is_link(t_file *file);
int					is_exec(t_file *file);
void				print_file_name(t_file *file, t_flag flag);

/*
** ls_without_l.c
*/
void				ls_without_l(t_flag flag, t_file *arg_dirs);

#endif
