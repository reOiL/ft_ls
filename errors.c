#include "ft_ls.h"

int 	print_error(int code, char *str)
{
	if (code == 22)
		ft_printf("ft_ls: %s: %c\n", strerror(code), str[0]);
	else
		ft_printf("ft_ls: %s: %s\n", strerror(code), str);
	return (0);
}