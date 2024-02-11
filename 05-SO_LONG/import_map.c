#include "so_long.h"

int	size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines)
{
	char *tmp;
	
	tmp = get_next_line(fd);
	if(!tmp)
		return (1);
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
	return (0);
}

char **read_map(int fd, unsigned int nb_columns, unsigned int nb_lines)
{
	unsigned int	j;
	char **tab;

	j = 0;
	tab = ft_calloc((nb_lines + 1), sizeof (char*));
	if (!tab)
		return (NULL);
	while (j < nb_lines)
	{
		tab[j] = ft_calloc((nb_columns + 1), sizeof (char));
		if(!tab[j])
			return (NULL);
		tab[j] = get_next_line(fd);
		j++;
	}
	close (fd);
	return (tab);
}

char **build_tab(int fd, unsigned int nb_columns, unsigned int nb_lines)
{
	char	**tab;
	unsigned int		i;
	unsigned int		j;
	
	tab = read_map(fd, nb_columns, nb_lines);
	j = 1;
	while (j < nb_lines)
	{
		i = 1;
		while (i < nb_columns)
		{
			if (j != (nb_lines - 1) && i != (nb_columns - 1) && tab[j][i] == '1')
				tab[j][i] = '2';
			i++;
		}
		j++;
	}
	return(tab);
}
