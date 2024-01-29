#include "so_long.h"

int	main()
{
	t_window *w_vars;
	t_list_image *li_vars;

	w_vars = malloc(sizeof(t_window));
	if (!w_vars)
		exit (1);
	li_vars = malloc(sizeof(t_list_image));
	if (!li_vars)
		exit (1);

	//li_vars->w_vars->mlx = w_vars->mlx;
	li_vars->img0 = NULL;


	//count lines and columns to build table
	w_vars->fd = open("Maps/map.ber", O_RDONLY);
	size_of_map(w_vars->fd, &w_vars->nb_columns, &w_vars->nb_lines);
	close(w_vars->fd);

/*	//read map and build table to verify its validity
	w_vars->fd = open("Maps/map.ber", O_RDONLY);
	w_vars->tab = read_map(w_vars->fd, w_vars->nb_columns, w_vars->nb_lines);
	close(w_vars->fd);*/

	//display window, fill with images and update
	w_vars->fd = open("Maps/map.ber", O_RDONLY);
	create_images(li_vars, w_vars);
	complete_display(w_vars, li_vars);
	close(w_vars->fd);
	free_tab(w_vars->tab);
	/*while (w_vars->nb_lines >= 0)
	{
		free(w_vars->tab[w_vars->nb_lines]);
		w_vars->nb_lines -= 1;
	}
	free(w_vars->tab);*/
	free(w_vars);
	free(li_vars);
	return (0);
}
