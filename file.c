//
// Created by Johnny Webber on 02/01/2020.
//

#include "ft_ls.h"

void	*free_t_file(t_file *file, size_t size)
{
	(void)size;
	if(!file)
		return (NULL);
	if(file->filename)
		ft_strdel(&file->filename);
	ft_memdel((void**)&file);
	return (NULL);
}