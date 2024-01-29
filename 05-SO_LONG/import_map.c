#include "so_long.h"

void size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines)
{
	*nb_columns = ft_strlen(get_next_line(fd)) - 1;
	*nb_lines = 1;
	while (get_next_line(fd))
		*nb_lines += 1;
}


char **read_map(int fd, unsigned int nb_columns, unsigned int nb_lines)
{
	unsigned int	i;
	unsigned int j;
	char **tab;

	i = 0;
	j = 0;
	tab = ft_calloc((nb_lines + 1), sizeof (char*));
	if (!tab)
		return (NULL);
	while (i < nb_lines)
	{
		tab[i] = ft_calloc((nb_columns + 1), sizeof (char));
		if(!tab[i])
			return (NULL);
		ft_strcpy(tab[i], get_next_line(fd));
		i++;
	}
	close (fd);
	return (tab);
}
