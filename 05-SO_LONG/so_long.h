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

//t_win1 initilise dans main (main.c)
//t_win2 utilise dans update (refresh_displays.c)
//t_win3 utilise dans key_hook (events.c) 

typedef struct s_image{
	unsigned int	x_tab;
	unsigned int	y_tab;
	unsigned int	x_map;
	unsigned int	y_map;
	void			*image;
	void			*image_0;
}	t_image;

//t_img1 initialise dans display_images (display_images.c)

typedef struct s_list_image{
	t_window	*t_win1;
	void		*img_0;
	void		*img_1;
	void		*img_2;
	void		*img_e;
	void		*img_c;
	void		*img_p;
}	t_list_image;

//t_list1 initialise dans complete_display (so_long.c)

typedef struct s_position_image{
	t_list_image	*t_list1;
	char			*image;
	unsigned int	x_tab;
	unsigned int	y_tab;
	unsigned int	x_map;
	unsigned int	y_map;
}	t_position_image;

//t_pos1 initialise dans key_hook (events.c)
// rajouter initialisation t_list1 


void	complete_display(t_window *t_win);

void	size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines);
char	**read_map(int fd, unsigned int nb_columns, unsigned int nb_lines);

void	create_images(t_list_image *t_list);
void	which_image(char **tab, t_image *t_img, t_list_image *t_list);
void	display_images(t_list_image *t_list);//t_window *t_win);
//char	**stock_image(t_window *t_win, char *image);

int		key_hook(int key, void *param);
int		window_hook(int event, void* mlx);

void	init_t_window(t_window **t_win);
void	init_t_image(t_image **t_img);
void	init_t_list_image(t_list_image **t_list, t_window *t_win);
void	init_t_position_image(t_position_image **t_pos);

void	destroy_all(t_list_image *t_list, t_window *t_win);
void	free_tab(char **tab);

int		update(void *param);
int		find_image(t_window *t_win, t_position_image *t_pos);
void	move_image_up(t_window *t_win, t_position_image *t_pos);

#endif