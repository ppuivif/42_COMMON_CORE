#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef SIZE
#  define SIZE 64
# endif


# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_profile.h"
# include "GNL/get_next_line.h"
# include "LIBFT/libft.h"
# include <stdint.h>
# include <stdlib.h>

typedef struct s_window{
	int				fd;
	char			**tab;
	unsigned int	nb_lines;
	unsigned int	nb_columns;
}	t_window;

typedef struct s_image{
	unsigned char	x;
	unsigned char	y;
	void			**img;
	void			**img0;
}	t_image;

void	complete_display(t_window *w_vars);
void	size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines);
char	**read_map(int fd, unsigned int nb_columns, unsigned int nb_lines);
void	which_image(char **tab, void *mlx, t_image *i_vars);
//void	*which_image(char **tab, void *mlx, unsigned int x, unsigned int y);
void	display_images(t_window *w_vars, void *mlx, void *win);

#endif