#ifndef FLOOD_FILL_REV01_H
# define FLOOD_FILL_REV01_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	flood_fill(char **tab, t_point size, t_point begin);
void	ft_putstr(char *str);

#endif