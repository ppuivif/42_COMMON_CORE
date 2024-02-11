#include "so_long.h"

int	main(int argc, char **argv)
{

	t_window	*t_win1;
	

	if (argc == 2)
	{

		init_t_window(&t_win1);
	
	//check_file_ber
	
		check_map_validity(t_win1, argv[1]);
	//	t_win1->fd = open(argv[1], O_RDONLY);
		
	//count lines and columns to build table
	
/*	//read map and build table to verify its validity
	t_win1->fd = open("Maps/map.ber", O_RDONLY);
	t_win1->tab = read_map(t_win1->fd, t_win1->nb_columns, t_win1->nb_lines);
	close(t_win1->fd);*/

	//display window, fill with images and update
	
	
		complete_display(t_win1);
		
		free_tab(t_win1->tab);
	/*while (t_win1->nb_lines >= 0)
	{
		free(t_win1->tab[t_win1->nb_lines]);
		t_win1->nb_lines -= 1;
	}
	free(t_win1->tab);*/
		free(t_win1);
	}
	else
		printf("Error\nFile .ber missing for map\n");
	return (0);
}
