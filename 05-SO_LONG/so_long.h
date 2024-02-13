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
# include <stdio.h>//attention

typedef struct s_window{
	int				fd;
	char			**tab;
	char			**tab_cpy;
	unsigned int	nb_lines;
	unsigned int	nb_columns;
	unsigned int	nb_collect_tot;
	void 			*mlx;
	void 			*win;
	unsigned int	x0_image_p;
	unsigned int	y0_image_p;
}	t_window;

//t_win1 initialized in main (main.c)
//and free in main 

typedef struct s_image{
	unsigned int	x_tab;
	unsigned int	y_tab;
	unsigned int	x_map;
	unsigned int	y_map;
	void			*image;
	void			*image_0;
}	t_image;

//t_img1 initialized in main_display (display_images.c)
//and free in main_display

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

//t_list1 initialized in main_display (main_display_images.c)
//and free in main display

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

//t_pos1 initialized in main_display (main_display_images.c) and free
//t_pos2 used in key_hook (events.c) 
//t_pos3 used in window_hook (events.c) 
//t_pos4 used in anim_char (events.c) 


void	main_display(t_window *t_win);

int		size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines);
char	**read_map(int fd, unsigned int nb_columns, unsigned int nb_lines);
char	**build_tab(int fd, unsigned int nb_columns, unsigned int nb_lines);

void	create_tiles(t_list_image *t_list);
void	create_sprites(t_list_image *t_list);
void	which_image(char **tab, t_image *t_img, t_list_image *t_list);
void	display_images(t_list_image *t_list);

int		key_hook(int key, void *param);
int		window_hook(int event, void *param);

void	init_t_window(t_window **t_win);
void	init_t_window_cpy(t_window *t_win);
void	init_t_image(t_image **t_img);
void	init_t_list_image(t_list_image **t_list, t_window *t_win);
void	init_t_position_image(t_position_image **t_pos,
			t_list_image *t_list1, t_window *t_win);

void	destroy_all(t_list_image *t_list);
void	destroy_image(t_list_image *t_list);
void	free_t_list(t_list_image *t_list, char *error_message);
void	free_t_win(t_window *t_win, char *error_message);
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
void	verify_columns_and_lines(t_window *t_win);
void	verify_extern_wall(t_window *t_win);
void	verify_nb_collectibles(t_window *t_win);
void	verify_nb_exit(t_window *t_win);
void	verify_nb_character(t_window *t_win);
void	find_image_p(t_window *t_win);
int		find_image(t_window *t_win, char c);
void	flood_fill(t_window *t_win);
void	verify_way_validity(t_window *t_win);


#endif