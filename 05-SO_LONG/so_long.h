#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef SIZE
#  define SIZE 64
# endif


# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_profile.h"
# include "GNL/get_next_line.h"
# include "LIBFT/libft.h"
//# include "FT_PRINTF/libftprintf.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
//# include <stdbool.h>
# include <stdio.h>//attention

typedef struct s_window{
	int				fd;
	char			**tab;
	unsigned int	nb_lines;
	unsigned int	nb_columns;
	unsigned int	nb_collect_tot;
	void 			*mlx;
	void 			*win;
	unsigned int	x0_image_p;
	unsigned int	y0_image_p;
	unsigned int	x0_image_e;
	unsigned int	y0_image_e;
}	t_window;

//t_win1 initilise dans main (main.c)

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
	void		*img_p1;
	void		*img_p2;
	void		*img_p3;
	void		*img_p4;
	void		*img_p5;
}	t_list_image;

//t_list1 initialise dans complete_display (so_long.c)

typedef struct s_position_image{
	t_window		*t_win1;
	t_list_image	*t_list1;
	char			*image;
	unsigned int	x_tab;
	unsigned int	y_tab;
	unsigned int	x_map;
	unsigned int	y_map;
	unsigned int	x0_image_p;//current position of the character
	unsigned int	y0_image_p;//current position of the character
	unsigned int	x1_image_p;//next position of the character
	unsigned int	y1_image_p;//next position of the character
	unsigned int	move;
	unsigned int	nb_collect;
	unsigned int	anim_time;
	unsigned int	move_possible;
}	t_position_image;

//t_pos1 initialise dans complete_display (so_long.c)
//t_pos2 utilise dans key_hook (events.c) 
//t_pos3 utilise dans window_hook (events.c) 
//t_pos4 utilise dans anim_char (events.c) 


void	complete_display(t_window *t_win);

int		size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines);
char	**read_map(int fd, unsigned int nb_columns, unsigned int nb_lines);
char	**build_tab(int fd, unsigned int nb_columns, unsigned int nb_lines);

void	create_tiles(t_list_image *t_list);
void	create_sprites(t_list_image *t_list);
void	which_image(char **tab, t_image *t_img, t_list_image *t_list);
void	display_images(t_list_image *t_list);//t_window *t_win);

int		key_hook(int key, void *param);
int		window_hook(int event, void *param);

void	init_t_window(t_window **t_win);
void	init_t_image(t_image **t_img);
void	init_t_list_image(t_list_image **t_list, t_window *t_win);
void	init_t_position_image(t_position_image **t_pos,
			t_list_image *t_list1, t_window *t_win);

void	destroy_all(t_list_image *t_list);
void	free_tab(char **tab);

int		update(t_position_image *t_pos);
void	move_image_1(t_position_image *t_pos);
void	move_image_2(t_position_image *t_pos);
void	move_image_up(t_position_image *t_pos);
void	move_image_down(t_position_image *t_pos);
void	move_image_left(t_position_image *t_pos);
void	move_image_right(t_position_image *t_pos);
int		anim_char(void *param);
void	first_anim_char(t_position_image *t_pos);
void	second_anim_char(t_position_image *t_pos);
void	third_anim_char(t_position_image *t_pos);
void	to_collectible(t_position_image *t_pos);
void	to_exit(t_position_image *t_pos);

void	check_map_validity(t_window *t_win, char *argv);
void	columns_and_lines(t_window *t_win);
void	extern_wall(t_window *t_win);
void	count_collectibles(t_window *t_win);
void	count_exit(t_window *t_win);
void	count_character(t_window *t_win);
void	find_image_p(t_window *t_win);
void	find_image_e(t_window *t_win);
void	flood_fill(t_window *t_win);




#endif