#include "so_long.h"

void	check_map_validity(t_window *t_win, char *argv)
{
	int	size;
	
	t_win->fd = open(argv, O_RDONLY);
	size = size_of_map(t_win->fd, &t_win->nb_columns, &t_win->nb_lines);
	close(t_win->fd);

	t_win->fd = open(argv, O_RDONLY);
	t_win->tab = build_tab(t_win->fd, t_win->nb_columns, t_win->nb_lines);
	close(t_win->fd);
	if (size == 1)
	{
		printf("Error\nFile .ber is empty\n");
		exit(1);
	}
	
	columns_and_lines(t_win);
	extern_wall(t_win);
	count_collectibles(t_win);
	count_exit(t_win);
	count_character(t_win);
//	flood_fill(t_win);
	
	
	
	
	


}

size_t	ft_strlen_nl(char *str)
{
	size_t len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	return (len);
}

void	columns_and_lines(t_window *t_win)
{
	char	**tab;
	int		j;

	tab = t_win->tab;
	j = 0;
	while (tab[j])
	{
		if(ft_strlen_nl(tab[j]) == t_win->nb_columns)
			j++;
		else
		{
			printf("Error\nMap is not rectangular\n");
			exit(1);
		}
	}
}

void	extern_wall(t_window *t_win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (t_win->tab[j][i] && t_win->tab[j][i] != '\n')
	{
		if(t_win->tab[j][i] == '1')
			i++;
		else
		{
			printf("Error\nExtern wall isn't complete\n");
			exit(1);
		}
	}
	i = 0;
	j = t_win->nb_lines - 1;
	while (t_win->tab[j][i] && t_win->tab[j][i] != '\n')
	{
		if(t_win->tab[j][i] == '1')
			i++;
		else
		{
			printf("Error\nExtern wall isn't complete\n");
			exit(1);
		}
	}
	i = 0;
	j = 0;
	while (t_win->tab[j])
	{
		if(t_win->tab[j][i] == '1')
			j++;
		else
		{
			printf("Error\nExtern wall isn't complete\n");
			exit(1);
		}
	}
	i = t_win->nb_columns - 1;
	j = 0;
	while (t_win->tab[j])
	{
		if(t_win->tab[j][i] == '1')
			j++;
		else
		{
			printf("Error\nExtern wall isn't complete\n");
			exit(1);
		}
	}
}

void	count_collectibles(t_window *t_win)
{
	int		i;
	int		j;
	char	**tab;

	tab = t_win->tab;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if(tab[j][i] == 'C')
				t_win->nb_collect_tot += 1;
			i++;
			
		}
		j++;
	}
	if (t_win->nb_collect_tot == 0)
	{
		printf("Error\nCollectibles are missing\n");
		exit(1);
	}	
}

void	count_exit(t_window *t_win)
{
	int		i;
	int		j;
	int		nb_exit;

	j = 0;
	nb_exit = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if(t_win->tab[j][i] == 'E')
				nb_exit++;
			i++;
		}
		j++;
	}
	if (nb_exit != 1)
	{
		if (nb_exit == 0)
			printf("Error\nExit is missing\n");
		if (nb_exit > 1)
			printf("Error\nThere are too many exits\n");
		exit(1);
	}
}

void	count_character(t_window *t_win)
{
	int		i;
	int		j;
	int		nb_char;

	j = 0;
	nb_char = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if(t_win->tab[j][i] == 'P')
				nb_char++;
			i++;
		}
		j++;
	}
	if (nb_char != 1)
	{
		if (nb_char == 0)
			printf("Error\nCharacter is missing\n");
		if (nb_char > 1)
			printf("Error\nThere are too many characters\n");
		exit(1);
	}
}

void find_image_p(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if(t_win->tab[j][i] == 'P')
			{
				t_win->x0_image_p = i;
				t_win->y0_image_p = j;
				printf("%d\n", t_win->x0_image_p);
				printf("%d\n", t_win->y0_image_p);
				return ;
			}
			i++;
		}
		j++;
	}
}

void find_image_e(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if(t_win->tab[j][i] == 'E')
			{
				t_win->x0_image_e = i;
				t_win->y0_image_e = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

/*	while ((t_pos->y_tab < t_pos->t_win1->nb_lines)) // && (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab]))
	{
		while ((t_pos->x_tab < t_pos->t_win1->nb_columns))// && (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab]))
		{
			if (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab] == *t_pos->image)
			{
				t_pos->x0_image_p = t_pos->x_tab;
				t_pos->y0_image_p = t_pos-		cd LIBFT && make && cd ..
>y_tab;
				return (1);
			}
			t_pos->x_tab++;
		}
		t_pos->x_tab = 0;
		t_pos->y_tab++;
	}
	return (0);*/


void	flood_fill(t_window *t_win)
{
	char			**tab;
	int	x;	
	int	y;	

 	tab = t_win->tab;
	find_image_p(t_win);
	find_image_e(t_win);
	x = t_win->x0_image_p;
	y = t_win->y0_image_p;
	if (y < 0 || y >= (int)t_win->nb_lines || x < 0 || x >= (int)t_win->nb_columns)
		exit (1);
	tab[y][x] = '1';
	if (y > 0)
	{
		if (tab[y - 1][x] == '0' || tab[y - 1][x] == 'C' || tab[y - 1][x] == 'E')
		{
			t_win->y0_image_p -= 1;
			flood_fill(t_win);
		}
	}
	if (y < (int)t_win->nb_lines - 1)
	{	
		if (tab[y + 1][x] == '0' || tab[y + 1][x] == 'C' || tab[y + 1][x] == 'E')
		{
			t_win->y0_image_p += 1;
			flood_fill(t_win);
		}
	}
	if (x > 0)
	{
		if(tab[y][x - 1] == '0' || tab[y][x - 1] == 'C' || tab[y][x - 1] == 'E')
		{
			t_win->x0_image_p -= 1;
			flood_fill(t_win);
		}
	}
	if (x < (int)t_win->nb_columns - 1)
	{
		if(tab[y][x + 1] == '0' || tab[y][x + 1] == 'C' || tab[y][x + 1] == 'E')
		{
			t_win->x0_image_p += 1;
			flood_fill(t_win);
		}
	}
}
