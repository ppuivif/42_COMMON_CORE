#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

char** make_area(char** zone, t_point size);
void	flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point cur, char to_fill);

#endif