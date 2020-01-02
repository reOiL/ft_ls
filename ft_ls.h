#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <sys/stat.h>
# include <dirent.h>

typedef struct	s_file {
			char *filename;
			struct stat s_stat;
}				t_file;

t_file	*get_directory_info(char *path);
t_list	*get_all_directory(char *path);
void	*free_t_file(t_file *file, size_t size);
char	*path_join(char *a, char *b);
#endif
