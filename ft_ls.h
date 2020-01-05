#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>

# define FLAG_l		0x1
# define FLAG_R		0x2
# define FLAG_a		0x4
# define FLAG_r		0x8
# define FLAG_t		0x10

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

//acrights_helper.c
char				get_filetype(t_file *file);
char				get_third_acright(t_file *file);
char				get_sixth_acright(t_file *file);
char				get_ninth_acright(t_file *file);
char				get_extended_attr(t_file *file);

// comporators.c - потом изменить название)
int					cmp_flag_t(t_file *f1, t_file *f2);
int					cmp_flag_ascii(t_file *f1, t_file *f2);
int					cmp_file_type(t_file *f1, t_file *f2);

//del_from_lists
void				del_all_hidden(t_file **files);
void 				del_all_files(t_file **files);
void				free_all(t_file **files);

//errors.c
int					print_error(int code, char *str);

//get_fileinfo_1.c
char				*get_count_bytes(t_file *file, t_maxlen maxlen, char *acr_hlnks);
char				*get_group_name(t_file *file, t_maxlen maxlen, char *acr_hlnks);
char				*get_user_name(t_file *file, t_maxlen maxlen, char *acr_hlnks);
char				*get_hard_links(t_file *file, t_maxlen maxlen, char *acrights);
char				*get_fileinfo(t_file *file, t_maxlen maxlen);

//get_fileinfo_2.c
char				*add_linkway(t_file *file, char *str);
char				*get_end_line(t_file *file, t_maxlen maxlen, char *acr_hlnks);

//l_flag_helper1.c
t_maxlen			initialize_maxlen(void);
t_maxlen			get_max_lengths(t_file *files);
size_t				get_blocks(t_file *files);
void				sort_files(t_file **files, t_flag flag);

//t_file_helper.c
void				del_tfile(t_file **files);
t_file 				*new_tfile(char *filename, char *path);
void				push_new_tfile(t_file **files, t_file *new_files);
void 				add_new_tfile(t_file **files, char *filename, char *path);

// utils.c
char				*path_join(char *a, char *b);
void				lst_data_swap(t_file *lst1, t_file *lst2);
void				sort_lst(t_file *lst, int (*cmp)(t_file *, t_file *), int asc);
void				sort_by_flag(t_file *lst, t_flag flag);
int					is_dir(t_file *file);

//ls_without_l.c
void				ls_without_l(t_flag flag, t_file *arg_dirs);
#endif
