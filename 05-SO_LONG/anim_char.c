#include "so_long.h"

int	anim_char(void *param)
{
	t_position_image *t_pos4;

	t_pos4 = (t_position_image *)param;
	if (t_pos4->anim_time == 10 * 5)
		first_anim_char(t_pos4);
	if (t_pos4->anim_time == 10 * 100)
		second_anim_char(t_pos4);
	if(t_pos4->anim_time == 10 * 350)
		third_anim_char(t_pos4);
	if(t_pos4->anim_time == 10 * 400)
	{
		t_pos4->x0_image_p = t_pos4->x1_image_p;
		t_pos4->y0_image_p = t_pos4->y1_image_p;
		t_pos4->move_possible = 1;
	}
	t_pos4->anim_time += 1;
	return(t_pos4->anim_time);
}

void	first_anim_char(t_position_image *t_pos)
{
	void	*mlx;
	void	*win;
	void	*img_0;
	void	*img_p3;
	int		x0;
	int		y0;
//	int		x1;
//	int		y1;
	
	mlx = t_pos->t_win1->mlx;
	win = t_pos->t_win1->win;
	img_0 = t_pos->t_list1->img_0;
	t_pos->image = 3; 
	create_sprites(t_pos);
	img_p3 = t_pos->t_list1->img_p3;
	x0 = t_pos->x0_image_p;
	y0 = t_pos->y0_image_p;
//	x1 = t_pos->x1_image_p;
//	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(mlx, win, img_0, x0 * SIZE, y0 * SIZE);
	mlx_put_image_to_window(mlx, win, img_p3, x0 * SIZE, y0 * SIZE);
}

void	second_anim_char(t_position_image *t_pos)
{
	void	*mlx;
	void	*win;
	void	*img_0;
	void	*img_p4;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	
	mlx = t_pos->t_win1->mlx;
	win = t_pos->t_win1->win;
	img_0 = t_pos->t_list1->img_0;
	t_pos->image = 4; 
	create_sprites(t_pos);
	img_p4 = t_pos->t_list1->img_p4;
	x0 = t_pos->x0_image_p;
	y0 = t_pos->y0_image_p;
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(mlx, win, img_0, x0 * SIZE, y0 * SIZE);
	mlx_put_image_to_window(mlx, win, img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(mlx, win, img_p4, x1 * SIZE, y1 * SIZE);
}

void	third_anim_char(t_position_image *t_pos)
{
	void	*mlx;
	void	*win;
	void	*img_0;
	void	*img_p;
//	int		x0;
//	int		y0;
	int		x1;
	int		y1;
	
	mlx = t_pos->t_win1->mlx;
	win = t_pos->t_win1->win;
	img_0 = t_pos->t_list1->img_0;
	img_p = t_pos->t_list1->img_p;
//	x0 = t_pos->x0_image_p;
//	y0 = t_pos->y0_image_p;
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(mlx, win, img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(mlx, win, img_p, x1 * SIZE, y1 * SIZE);
}
/*	mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_0, t_pos4->x0_image_p * SIZE, ((t_pos4->y0_image_p + 1) * SIZE));
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_0, t_pos4->x0_image_p * SIZE, ((t_pos4->y0_image_p) * SIZE));
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_p, t_pos4->x0_image_p * SIZE, ((t_pos4->y0_image_p) * SIZE));
	}*/
