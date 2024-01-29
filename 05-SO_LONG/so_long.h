#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef SIZE
#  define SIZE 64
# endif


# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_profile.h"
# include "GNL/get_next_line.h"
# include "LIBFT/libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>//attention

typedef struct s_window{
	int				fd;
	char			**tab;
	unsigned int	nb_lines;
	unsigned int	nb_columns;
	void 			*mlx;
	void 			*win;
}	t_window;

typedef struct s_image{
	unsigned int	x;
	unsigned int	y;
	void			*img;
	void			*img0;
}	t_image;

typedef struct s_list_image{
	t_window	*w_vars;
	void		*img0;
	void		*img1;
	//void		*img2;
	//void		*imgE;
	//void		*imgC;
	void		*imgP;
}	t_list_image;

void	complete_display(t_window *w_vars, t_list_image *li_vars);
void	size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines);
char	**read_map(int fd, unsigned int nb_columns, unsigned int nb_lines);
//void	create_images(t_list_image *li_vars);
void	create_images(t_list_image *li_vars, t_window *w_vars);
void	which_image(char **tab, t_image *i_vars, t_list_image *li_vars);
void	display_images(t_window *w_vars, t_list_image *li_vars);
//char	**stock_image(t_window *w_vars, char *img);
int		key_hook(int key, void *param);
int		window_hook(int event, void* mlx);
void	destroy_all(t_list_image *li_vars);
void	free_tab(char **tab);
int		update(void *param);


#endif