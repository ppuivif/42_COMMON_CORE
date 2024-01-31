#include "so_long.h"

void size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines)
{
	char *tmp;
	
	tmp = get_next_line(fd);
	*nb_columns = ft_strlen(tmp) - 1;
	free(tmp);
	tmp = NULL;
	*nb_lines = 1;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
		*nb_lines += 1;
	}
	free(tmp);
	tmp = NULL;
}


char **read_map(int fd, unsigned int nb_columns, unsigned int nb_lines)
{
	unsigned int	i;
	unsigned int j;
	char *tmp;
	char **tab;

	i = 0;
	j = 0;
	tmp = NULL;
	tab = ft_calloc((nb_lines + 1), sizeof (char*));
	if (!tab)
		return (NULL);
	while (i < nb_lines)
	{
		tab[i] = ft_calloc((nb_columns + 1), sizeof (char));
		if(!tab[i])
			return (NULL);
		tmp = get_next_line(fd);
		ft_strcpy(tab[i], tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
	close (fd);
	return (tab);
}
