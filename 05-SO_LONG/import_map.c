#include "so_long.h"

void	size_of_map(t_window *t_win)
{
	char *tmp;
	
	tmp = get_next_line(t_win->fd);
	if(!tmp)
	{
		printf("%s", "Error\nMap couldn't be read\n");
		exit (EXIT_FAILURE);
	}
	t_win->nb_columns = ft_strlen(tmp) - 1;
	free(tmp);
	tmp = NULL;
	t_win->nb_lines = 1;
	tmp = get_next_line(t_win->fd);
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(t_win->fd);
		t_win->nb_lines += 1;
	}
	free(tmp);
	tmp = NULL;
}

void	read_map(t_window *t_win)
{
	unsigned int	j;

	j = 0;
	t_win->tab = ft_calloc((t_win->nb_lines + 1), sizeof (char*));
	if (!t_win->tab)
	{
		printf("%s", "Error\nArray couldn't be created\n");
		exit (EXIT_FAILURE);
	}
	while (j < t_win->nb_lines)
	{
		/*if (j == t_win->nb_lines)
			t_win->tab[j] = ft_calloc((t_win->nb_columns + 1), sizeof (char));
		else
			t_win->tab[j] = ft_calloc((t_win->nb_columns + 2), sizeof (char));
		if(!t_win->tab[j])
		{
			printf("%s", "Error\nArray couldn't be created\n");
			exit (EXIT_FAILURE);
		}*/
		t_win->tab[j] = get_next_line(t_win->fd);
		j++;
	}
	close (t_win->fd);
}

void	build_tab(t_window *t_win)
{
	unsigned int		i;
	unsigned int		j;
	
	t_win->tab_modified = ft_tab_cpy(t_win);
	j = 1;
	while (t_win->tab_modified[j])
	{
		i = 1;
		while (t_win->tab_modified[j][i])
		{
			if (j != (t_win->nb_lines - 1) && i != (t_win->nb_columns - 1) && t_win->tab_modified[j][i] == '1')
				t_win->tab_modified[j][i] = '2';
			i++;
		}
		j++;
	}
}

char	**ft_tab_cpy(t_window *t_win)
{
	unsigned int	i;
	unsigned int	j;
	char			**new_tab;

	j = 0;
	new_tab = ft_calloc(t_win->nb_lines + 1, sizeof(char *));
	if (!new_tab)
	{
			printf("%s", "Error\nArray couldn't be created\n");
			exit (EXIT_FAILURE);
	}
	while (j < t_win->nb_lines && t_win->tab[j])
	{
		i = 0;
		new_tab[j] = ft_calloc(t_win->nb_columns + 1, sizeof(char));
		if (!new_tab[j])
		{
			printf("%s", "Error\nArray couldn't be created\n");
			exit (EXIT_FAILURE);
		}
		while (i < t_win->nb_columns && t_win->tab[j][i] && t_win->tab[j][i] != '\n')
		{
			new_tab[j][i] = t_win->tab[j][i];
			i++;
		}
		j++;
	}
	return (new_tab);
}

