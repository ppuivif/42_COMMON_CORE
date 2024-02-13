#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	*t_win1;

	if (argc == 2)
	{
		//check name of file (exist, conform)
		init_t_window(&t_win1);
		check_map_validity(t_win1, argv[1]);
		main_display(t_win1);
		free_tab(t_win1->tab);
		free_tab(t_win1->tab_cpy);
		free(t_win1);
	}
	else
		printf("Error\nFile .ber missing for map\n");
	return (0);
}
