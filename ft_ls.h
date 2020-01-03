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

//l_flag_hepler1.c
t_maxlen			initialize_maxlen(void);
t_maxlen			get_max_lengths(t_file *files);
size_t				get_blocks(t_file *files);

//get_fileinfo_1.c
char	*get_fileinfo(t_file *file, t_maxlen maxlen);

//get_fileinfo_2.c
char 	*get_end_line(t_file *file, t_maxlen maxlen, char *acr_hlnks);

#endif
