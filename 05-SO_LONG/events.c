#include "so_long.h"

int update(t_position_image *t_pos)// to update on events
{
	mlx_on_event(t_pos->t_win1->mlx, t_pos->t_win1->win, MLX_KEYDOWN, key_hook, t_pos);
	mlx_on_event(t_pos->t_win1->mlx, t_pos->t_win1->win, MLX_WINDOW_EVENT, window_hook, t_pos);
	return (0);
}

int key_hook(int key, void *param)
{
	t_position_image *t_pos2;
	
	t_pos2 = (t_position_image*)param;
	t_pos2->image = "P";
	if (t_pos2->x0_image_p == 0 && t_pos2->y0_image_p == 0)
		find_image_p(t_pos2);
	if(key == 41) // 41 is the key code for escape
		mlx_loop_end(t_pos2->t_win1->mlx);
	if((key == 26 || key == 82) && t_pos2->move_possible == 1) //  is the key code for W (up) and top arrow
		move_image_up(t_pos2);
	if((key == 22 || key == 81) && t_pos2->move_possible == 1) //  is the key code for S (down) and down arrow
		move_image_down(t_pos2);
	if((key == 6 || key == 80) && t_pos2->move_possible == 1) //  is the key code for A (left) and left arrow
		move_image_left(t_pos2);
	if((key == 7 || key == 79) && t_pos2->move_possible == 1) //  is the key code for D (right) and right arrow
		move_image_right(t_pos2);
	return (0);
}

int window_hook(int event, void *param)
{
	t_position_image *t_pos3;

	t_pos3 = (t_position_image *)param;
	if(event == 0) // 0 is when we trigger the close of the window (by clicking the cross for example)
		mlx_loop_end(t_pos3->t_win1->mlx);
	return (0);
}

int find_image_p(t_position_image *t_pos)
{
	while ((t_pos->y_tab < t_pos->t_win1->nb_lines)) // && (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab]))
	{
		while ((t_pos->x_tab < t_pos->t_win1->nb_columns))// && (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab]))
		{
			if (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab] == *t_pos->image)
			{
				t_pos->x0_image_p = t_pos->x_tab;
				t_pos->y0_image_p = t_pos->y_tab;
				return (1);
			}
			t_pos->x_tab++;
		}
		t_pos->x_tab = 0;
		t_pos->y_tab++;
	}
	return (0);
}

void	move_image_up(t_position_image *t_pos)
{
	t_pos->image = "P";
	t_pos->x1_image_p = t_pos->x0_image_p;
	t_pos->y1_image_p = t_pos->y0_image_p - 1;
	move_image_1(t_pos);
}

void	move_image_down(t_position_image *t_pos)
{
	t_pos->image = "P";
	t_pos->x1_image_p = t_pos->x0_image_p;
	t_pos->y1_image_p = t_pos->y0_image_p + 1;
	move_image_1(t_pos);
}

void	move_image_left(t_position_image *t_pos)
{
	t_pos->image = "P1";
	t_pos->x1_image_p = t_pos->x0_image_p - 1;
	t_pos->y1_image_p = t_pos->y0_image_p;
	move_image_1(t_pos);
}

void	move_image_right(t_position_image *t_pos)
{
	t_pos->image = "P2";
	t_pos->x1_image_p = t_pos->x0_image_p + 1;
	t_pos->y1_image_p = t_pos->y0_image_p;	
	move_image_1(t_pos);
}

void	move_image_1(t_position_image *t_pos)
{
	int x1;
	int y1;

	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	if (t_pos->t_win1->tab[y1][x1] != '1' && t_pos->t_win1->tab[y1][x1] != '2')
	{
		if (t_pos->t_win1->tab[y1][x1] == 'C')
		{
			collectible(t_pos);
		}
		else if (t_pos->t_win1->tab[y1][x1] == 'E')
		{
			if (t_pos->nb_collect == t_pos->t_win1->nb_collect_tot)
				to_exit(t_pos);
		}
		else
		{
			move_image_2(t_pos);
			t_pos->x0_image_p = t_pos->x1_image_p;
			t_pos->y0_image_p = t_pos->y1_image_p;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
		}
	}
}

void	move_image_2(t_position_image *t_pos)
{
	void *mlx;
	void *win;
	void *img_0;
	void *img_p;
	int x0;
	int y0;
	int x1;
	int y1;

	mlx = t_pos->t_win1->mlx;
	win = t_pos->t_win1->win;
	img_0 = t_pos->t_list1->img_0;
	if (ft_strcmp(t_pos->image, "P") == 0)
		img_p = t_pos->t_list1->img_p;
	if (ft_strcmp(t_pos->image, "P1") == 0)
		img_p = t_pos->t_list1->img_p1;
	if (ft_strcmp(t_pos->image, "P2") == 0)
		img_p = t_pos->t_list1->img_p2;
	x0 = t_pos->x0_image_p;
	y0 = t_pos->y0_image_p;
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(mlx, win, img_0, x0 * SIZE, y0 * SIZE);
	mlx_put_image_to_window(mlx, win, img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(mlx, win, img_p, x1 * SIZE, y1 * SIZE);
}

void	collectible(t_position_image *t_pos)
{
	t_pos->anim_time = 0;
	t_pos->move_possible = 0;
	mlx_loop_hook(t_pos->t_win1->mlx, anim_char, t_pos);
	t_pos->move++;
	t_pos->t_win1->tab[t_pos->y1_image_p][t_pos->x1_image_p] = 0;
	t_pos->nb_collect++;
	printf("move counter = %d\n", t_pos->move);
	printf("well done, you caught %d collectible(s)\n", t_pos->nb_collect);
}

void	to_exit(t_position_image *t_pos)
{
	move_image_2(t_pos);
	t_pos->x0_image_p = t_pos->x1_image_p;
	t_pos->y0_image_p = t_pos->y1_image_p;
	t_pos->move++;
	printf("move counter = %d\n", t_pos->move);
	printf("				!GAME OVER!\n");
	mlx_loop_end(t_pos->t_win1->mlx);
}

