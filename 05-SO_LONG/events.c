#include "so_long.h"

int key_hook(int key, void *param)
{
	t_position_image *t_pos2;
	
	t_pos2 = (t_position_image*)param;
	t_pos2->image = "P";
	if (t_pos2->x_image_p == 0 && t_pos2->y_image_p == 0)
		find_image_p(t_pos2);
	if(key == 41) // 41 is the key code for escape
		mlx_loop_end(t_pos2->t_win1->mlx);
	if(key == 26 || key == 82) //  is the key code for W (up) and top arrow
		move_image_up(t_pos2);
	if(key == 22 || key == 81) //  is the key code for S (down) and down arrow
		move_image_down(t_pos2);
	if(key == 6 || key == 80) //  is the key code for A (left) and left arrow
		move_image_left(t_pos2);
	if(key == 7 || key == 79) //  is the key code for D (right) and right arrow
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
				t_pos->x_image_p = t_pos->x_tab;
				t_pos->y_image_p = t_pos->y_tab;
				return (1);
			}
			t_pos->x_tab++;
		}
		t_pos->x_tab = 0;
		t_pos->y_tab++;
	}
	return (0);
}

int	anim_char(void *param)
{
	t_position_image *t_pos4;

	t_pos4 = (t_position_image *)param;
	if (t_pos4->anim_time == 10 * 5)
	{
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_0, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p + 1) * SIZE));
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_p2, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p + 1) * SIZE));
	}
	if (t_pos4->anim_time == 10 * 100)
	{
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_0, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p + 1) * SIZE));
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_p3, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p + 1) * SIZE));
	}
	if(t_pos4->anim_time == 10 * 200)
	{
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_0, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p + 1) * SIZE));
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_0, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p) * SIZE));
		mlx_put_image_to_window(t_pos4->t_win1->mlx, t_pos4->t_win1->win, t_pos4->t_list1->img_p, t_pos4->x_image_p * SIZE, ((t_pos4->y_image_p) * SIZE));
	}
	t_pos4->anim_time += 1;
	return(t_pos4->anim_time);
}

void collectible(t_position_image *t_pos, int x, int y)
{
	if ((t_pos->t_win1->tab[y][x]) == 'C')
	{
		t_pos->anim_time = 0;
		mlx_loop_hook(t_pos->t_win1->mlx, anim_char, t_pos);
		//t_pos->anim_time = 0;
		t_pos->y_image_p -= 1;
		t_pos->move++;
		t_pos->t_win1->tab[y ][x] = 0;
		t_pos->nb_collect++;
		printf("move counter = %d\n", t_pos->move);
		printf("well done, you caught %d collectible(s)\n", t_pos->nb_collect);
	}
}

void	move_image(t_position_image *t_pos, int x, int y, int w, int z)
{
	void *mlx;
	void *win;
	void *img_0;
	void *img_p;
	
	mlx = t_pos->t_win1->mlx;
	win = t_pos->t_win1->win;
	img_0 = t_pos->t_list1->img_0;
	img_p = t_pos->t_list1->img_p;

	mlx_put_image_to_window(mlx, win, img_0, x * SIZE, y * SIZE);
	mlx_put_image_to_window(mlx, win, img_0, w * SIZE, z * SIZE);
	mlx_put_image_to_window(mlx, win, img_p, w * SIZE, z * SIZE);
}

void	move_image_up(t_position_image *t_pos)
{
	int x;
	int y;

	x = t_pos->x_image_p;
	y = t_pos->y_image_p;
	if (t_pos->t_win1->tab[y - 1][x] != '1' && t_pos->t_win1->tab[y - 1][x] != '2')
	{
		if (t_pos->t_win1->tab[y - 1][x] == 'C')
			collectible(t_pos, x, y);
		else if (t_pos->t_win1->tab[y - 1][x] != 'E')
		{
			move_image(t_pos, x, y, x, y -1);
			t_pos->y_image_p -= 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
		}
		else if (t_pos->nb_collect == t_pos->t_win1->nb_collect_tot)
		{
			move_image(t_pos, x, y, x, y - 1);
			t_pos->y_image_p -= 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
			printf("				!GAME OVER!\n");
			mlx_loop_end(t_pos->t_win1->mlx);
		}
	}
}

void	move_image_down(t_position_image *t_pos)
{
	int x;
	int y;

	x = t_pos->x_image_p;
	y = t_pos->y_image_p;
	if (t_pos->t_win1->tab[y + 1][x] != '1' && t_pos->t_win1->tab[y + 1][x] != '2')
	{
		collectible(t_pos, x, y + 1);
		if (t_pos->t_win1->tab[y + 1][x] != 'E')
		{
			move_image(t_pos, x, y, x, y + 1);
			t_pos->y_image_p += 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
		}
		else if (t_pos->nb_collect == t_pos->t_win1->nb_collect_tot)
		{
			move_image(t_pos, x, y, x, y + 1);
			t_pos->y_image_p += 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
			printf("				!GAME OVER!\n");
			mlx_loop_end(t_pos->t_win1->mlx);
		}
	}
}

void	move_image_left(t_position_image *t_pos)
{
	int x;
	int y;

	x = t_pos->x_image_p;
	y = t_pos->y_image_p;
	if (t_pos->t_win1->tab[y][x - 1] != '1' && t_pos->t_win1->tab[y][x - 1] != '2')
	{
		collectible(t_pos, x - 1, y);
		if (t_pos->t_win1->tab[y][x - 1] != 'E')
		{
			move_image(t_pos, x, y, x - 1, y);
			t_pos->x_image_p -= 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
		}
		else if (t_pos->nb_collect == t_pos->t_win1->nb_collect_tot)
		{
			move_image(t_pos, x, y, x - 1, y);
			t_pos->x_image_p -= 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
			printf("				!GAME OVER!\n");
			mlx_loop_end(t_pos->t_win1->mlx);
		}
	}
}

void	move_image_right(t_position_image *t_pos)
{
	int x;
	int y;

	x = t_pos->x_image_p;
	y = t_pos->y_image_p;
	if (t_pos->t_win1->tab[y][x + 1] != '1' && t_pos->t_win1->tab[y][x + 1] != '2')
	{
		collectible(t_pos, x + 1, y);
		if (t_pos->t_win1->tab[y][x + 1] != 'E')
		{
			move_image(t_pos, x, y, x + 1, y);
			t_pos->x_image_p += 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
		}
		else if (t_pos->nb_collect == t_pos->t_win1->nb_collect_tot)
		{
			move_image(t_pos, x, y, x + 1, y);
			t_pos->x_image_p += 1;
			t_pos->move++;
			printf("move counter = %d\n", t_pos->move);
			printf("				!GAME OVER!\n");
			mlx_loop_end(t_pos->t_win1->mlx);
		}
	}
}



