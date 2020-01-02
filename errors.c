#include "ft_ls.h"

int 	print_error(int code, char flag)
{
	ft_printf("ft_ls: %s: %c\n", strerror(code), flag);
	return (0);
}