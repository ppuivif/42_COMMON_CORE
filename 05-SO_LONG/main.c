#include "so_long.h"

int	main()
{
	t_window *t_win1;

	init_t_window(&t_win1);
	
	//count lines and columns to build table
	t_win1->fd = open("Maps/map.ber", O_RDONLY);
	size_of_map(t_win1->fd, &t_win1->nb_columns, &t_win1->nb_lines);
	t_win1->nb_collect_tot = 3;
	close(t_win1->fd);

/*	//read map and build table to verify its validity
	t_win1->fd = open("Maps/map.ber", O_RDONLY);
	t_win1->tab = read_map(t_win1->fd, t_win1->nb_columns, t_win1->nb_lines);
	close(t_win1->fd);*/

	//display window, fill with images and update
	t_win1->fd = open("Maps/map.ber", O_RDONLY);
	complete_display(t_win1);
	close(t_win1->fd);
	free_tab(t_win1->tab);
	/*while (t_win1->nb_lines >= 0)
	{
		free(t_win1->tab[t_win1->nb_lines]);
		t_win1->nb_lines -= 1;
	}
	free(t_win1->tab);*/
	free(t_win1);
	return (0);
}
