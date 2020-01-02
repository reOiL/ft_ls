//
// Created by Johnny Webber on 02/01/2020.
//

#ifndef FT_LS_ARGS_H
# define FT_LS_ARGS_H

#include "ft_ls.h"

#define FLAG_l	0x1
#define FLAG_R	0x2
#define FLAG_a	0x4
#define FLAG_r	0x8
#define FLAG_t	0x10

typedef size_t	t_flag;

int				parse_attr(char **str, int arg_count, t_file **lst, t_flag *flag);

#endif
