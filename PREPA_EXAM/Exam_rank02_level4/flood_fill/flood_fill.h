#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	print_tab(char **tab, t_point size);
char **create_new_tab(char **tab, t_point size);

#endif