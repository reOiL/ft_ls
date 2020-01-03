#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>

typedef struct		s_file
{
	char			*filename;
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

//t_file_helper.c
void				del_tfile(t_file **files);
t_file				*new_tfile(char *filename);
void				add_new_tfile(t_file **files, char *filename);
void				del_all_hidden(t_file **files);

//errors.c
int					print_error(int code, char *str);

//print_l_helper.c
t_maxlen			initialize_maxlen(void);
t_maxlen			get_max_lengths(DIR *dir);
char				*get_access_rights(struct dirent *dp, struct stat stats);

// reOiL functions
char	*path_join(char *a, char *b);
void    sort_lst(t_file *lst, int (*cmp)(t_file *, t_file *), int asc);

// comporators.c
int     cmp_flag_a(t_file *f1, t_file *f2);
#endif
