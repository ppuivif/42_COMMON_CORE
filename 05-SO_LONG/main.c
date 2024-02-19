#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	*t_win1;
// argv = (void *)argv;
//	t_win1 = NULL;
	if (argc == 2)
	{
		// check name of file (exist, conform)
		init_t_window(&t_win1);
		check_map_validity(t_win1, argv[1]);
//		free_t_win(t_win1, "free ok");
		
		main_display(t_win1);
	}
	else
		printf("Error\nFile .ber missing for map\n");
	return (0);
}
