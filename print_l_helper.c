#include "ft_ls.h"

char	*get_access_rights(struct dirent *dp, struct stat stats)
{
	char 	*acrights;

	acrights = ft_strnew(11);// ДОБАВИТЬ ПРОВЕРКУ И ERRNO
	acrights[0] = S_ISDIR(stats.st_mode) ? 'd' : '-'; // ПОТОМ ИЗМЕНИТЬ НА ОТДЕЛЬНУЮ ФУНКЦИЮ
	acrights[1] = (S_IRUSR & stats.st_mode) ? 'r' : '-';
	acrights[2] = (S_IWUSR & stats.st_mode) ? 'w' : '-';
	acrights[3] = (S_IXUSR & stats.st_mode) ? 'x' : '-';
	acrights[4] = (S_IRGRP & stats.st_mode) ? 'r' : '-';
	acrights[5] = (S_IWGRP & stats.st_mode) ? 'w' : '-';
	acrights[6] = (S_IXGRP & stats.st_mode) ? 'x' : '-';
	acrights[7] = (S_IROTH & stats.st_mode) ? 'r' : '-';
	acrights[8] = (S_IWOTH & stats.st_mode) ? 'w' : '-';
	acrights[9] = (S_IXOTH & stats.st_mode) ? 'x' : '-';
	acrights[10] = ' ';
	return (acrights); //get_hard_links(dp, stats, acrights));
}
