//
// Created by Владелец on 03.01.2020.
//

#include "ft_ls.h"

int cmp_flag_a(t_file *f1, t_file *f2)
{
    long long   a;

    a = f1->s_stat->st_ctim.tv_sec - f2->s_stat->st_ctim.tv_sec;
    if (a > 0)
        return (1);
    if (a < 0)
        return (-1);
    return (0);
}