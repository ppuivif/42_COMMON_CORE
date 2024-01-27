#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd = 0;
	unsigned int nb_columns = 0;
	unsigned int nb_lines = 0;
	char **tab;
	t_window *w_vars;

	w_vars = malloc(sizeof(t_window));
	if (!w_vars)
		return (1);
	fd = open("Maps/map.ber", O_RDONLY);
	size_of_map(fd, &nb_columns, &nb_lines);
	close(fd);
	fd = open("Maps/map.ber", O_RDONLY);
	tab = read_map(fd, nb_columns, nb_lines);
	close(fd);
	fd = open("Maps/map.ber", O_RDONLY);
	w_vars->fd = fd;
	w_vars->tab = tab;
	w_vars->nb_lines = nb_lines;
	w_vars->nb_columns = nb_columns;
	complete_display(w_vars);
	close(fd);
	free(w_vars);
	while (nb_lines >= 0)
	{
		free(tab[nb_lines]);
		nb_lines -= 1;
	}
	free (tab);
	return (0);
}