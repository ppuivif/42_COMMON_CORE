#include "so_long.h"

void	check_map_validity(t_window *t_win)
{
	void		*size_of_map;
	
	t_win->fd = open("Maps/map.ber", O_RDONLY);
	size_of_map = size_of_map(t_win->fd, &t_win->nb_columns, &t_win->nb_lines);
	
	t_win->nb_collect_tot = 3;
	
	close(t_win->fd);
	
	if (!size_of_map)
	{
		printf("Error\nThe file is empty");
		exit;
	}
	
	
	columns_and_lines
	
	extern_wall
	//one character only
	//one exit only
	nb_collect_tot //1 min
	way_validity


}

bool	columns_and_lines(t_window *t_win)
{
	char	**tab;

	tab = t_win->tab;
	while (tab[j])
	{
		if(ft_strlen(tab[j]) == t_win->nb_columns)
			j++;
		return (0);
	}
	return (1);
}

bool	extern_wall(t_window *t_win)
{
	char	**tab;

	tab = t_win->tab;
	while (tab[j])
	{



	}






}
