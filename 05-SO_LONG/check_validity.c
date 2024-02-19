#include "so_long.h"

void	check_map_validity(t_window *t_win, char *argv)
{
	t_win->fd = open(argv, O_RDONLY);
	size_of_map(t_win);
	close(t_win->fd);
	t_win->fd = open(argv, O_RDONLY);
	read_map(t_win);
	close(t_win->fd);
	t_win->tab_cpy = ft_tab_cpy(t_win);

	build_tab(t_win);

//	printf("%p\n", t_win->tab);

	int i = 0;
	while (t_win->tab[i])
	{
		free(t_win->tab[i]);
		i++;
	}
	if (t_win->tab)
		free(t_win->tab);
	t_win->tab = NULL;
//	free_tab(&t_win->tab);//free a valider

//	printf("%p\n", t_win->tab);
	
/*	if (size == 0)
		free_t_win(t_win, "Error\nFile .ber is empty\n");*/
	verify_columns_and_lines(t_win);
	verify_invalid_Z(t_win);
	verify_extern_wall(t_win);
	verify_nb_collectibles(t_win);
	verify_nb_exit(t_win);
	verify_nb_character(t_win);
	find_image_p(t_win);
	verify_way_validity(t_win);
}

size_t	ft_strlen_nl(char *str)
{
	size_t len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	return (len);
}

void	verify_columns_and_lines(t_window *t_win)
{
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		if(ft_strlen_nl(t_win->tab_cpy[j]) == t_win->nb_columns)
			j++;
		else
			free_t_win(t_win, "Error\nMap is not rectangular\n");
	}
}

void	verify_invalid_Z(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if(t_win->tab_cpy[j][i] != '0' && t_win->tab_cpy[j][i] != '1'
				&& t_win->tab_cpy[j][i] != '2' && t_win->tab_cpy[j][i] != 'C'
				&& t_win->tab_cpy[j][i] != 'E' && t_win->tab_cpy[j][i] != 'P'
				&& t_win->tab_cpy[j][i] != '\n')
				free_t_win(t_win, "Error\nThere is an invalid character in the map\n");
			i++;
		}
		j++;
	}
}

void	verify_extern_wall(t_window *t_win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (t_win->tab_cpy[j][i] && t_win->tab_cpy[j][i] != '\n')
	{
		if(t_win->tab_cpy[j][i] == '1')
			i++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
	i = 0;
	j = t_win->nb_lines - 1;
	while (t_win->tab_cpy[j][i] && t_win->tab_cpy[j][i] != '\n')
	{
		if(t_win->tab_cpy[j][i] == '1')
			i++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
	i = 0;
	j = 0;
	while (t_win->tab_cpy[j])
	{
		if(t_win->tab_cpy[j][i] == '1')
			j++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
	i = t_win->nb_columns - 1;
	j = 0;
	while (t_win->tab_cpy[j])
	{
		if(t_win->tab_cpy[j][i] == '1')
			j++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
}

void	verify_nb_collectibles(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if(t_win->tab_cpy[j][i] == 'C')
				t_win->nb_collect_tot += 1;
			i++;
			
		}
		j++;
	}
	if (t_win->nb_collect_tot == 0)
		free_t_win(t_win, "Error\nCollectibles are missing\n");
}

void	verify_nb_exit(t_window *t_win)
{
	int		i;
	int		j;
	int		nb_exit;

	j = 0;
	nb_exit = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if(t_win->tab_cpy[j][i] == 'E')
				nb_exit++;
			i++;
		}
		j++;
	}
	if (nb_exit != 1)
	{
		if (nb_exit == 0)
		free_t_win(t_win, "Error\nExit is missing\n");
		if (nb_exit > 1)
		free_t_win(t_win, "Error\nThere are too many exits\n");
	}
}

void	verify_nb_character(t_window *t_win)
{
	int		i;
	int		j;
	int		nb_char;

	j = 0;
	nb_char = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if(t_win->tab_cpy[j][i] == 'P')
				nb_char++;
			i++;
		}
		j++;
	}
	if (nb_char != 1)
	{
		if (nb_char == 0)
			free_t_win(t_win, "Error\nCharacter is missing\n");
		else if (nb_char > 1)
			free_t_win(t_win, "Error\nThere are too many characters\n");
	}
}

void find_image_p(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if(t_win->tab_cpy[j][i] == 'P')
			{
				t_win->x0_image_p = i;
				t_win->y0_image_p = j;
				return;
			}
			i++;
		}
		j++;
	}
}

int find_image(t_window *t_win, char c)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if(t_win->tab_cpy[j][i] == c)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	flood_fill(t_window *t_win)
{
	int	x;	
	int	y;

	x = t_win->x0_image_p;
	y = t_win->y0_image_p;
	if (t_win->tab_cpy[y - 1][x] != '1' && t_win->tab_cpy[y - 1][x] != '2')
	{
		t_win->tab_cpy[y - 1][x] = '1';
		t_win->y0_image_p -= 1;
		flood_fill(t_win);
		t_win->y0_image_p += 1;
	}
	if (t_win->tab_cpy[y][x - 1] != '1' && t_win->tab_cpy[y][x - 1] != '2')
	{
		t_win->tab_cpy[y][x - 1] = '1';
		t_win->x0_image_p -= 1;
		flood_fill(t_win);
		t_win->x0_image_p += 1;
	}
	if (t_win->tab_cpy[y + 1][x] != '1' && t_win->tab_cpy[y + 1][x] != '2')
	{
		t_win->tab_cpy[y + 1][x] = '1';
		t_win->y0_image_p += 1;
		flood_fill(t_win);
		t_win->y0_image_p -= 1;
	}
	if (t_win->tab_cpy[y][x + 1] != '1' && t_win->tab_cpy[y][x + 1] != '2')
	{
		t_win->tab_cpy[y][x + 1] = '1';
		t_win->x0_image_p += 1;
		flood_fill(t_win);
		t_win->x0_image_p -= 1;
	}
}

void	verify_way_validity(t_window *t_win)
{
	flood_fill(t_win);
	if (find_image(t_win, 'E') == 1 || find_image(t_win, 'C') == 1 )
		free_t_win(t_win, "Error\nExit not reachable\n");
}
