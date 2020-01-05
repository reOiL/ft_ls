#include "ft_ls.h"

int 	print_error(int code, char *str)
{
	if (code == EINVAL)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(str[0], 2);
		ft_putendl_fd("\nUsage: ./ft_ls -[adgGfltrRu] [file ...]", 2);
	}
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putchar_fd(str[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(code), 2);
		ft_strdel(&str);
	}
	return (0);
}