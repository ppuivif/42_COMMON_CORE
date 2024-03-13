/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:23:30 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/13 14:58:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_image_1(t_position_image *t_pos)
{
	int	x1;
	int	y1;

	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	if (t_pos->t_win1->tab_modified[y1][x1] != '1' &&
		t_pos->t_win1->tab_modified[y1][x1] != '2')
	{
		if (t_pos->t_win1->tab_modified[y1][x1] == 'C')
			to_collectible(t_pos);
		else if (t_pos->t_win1->tab_modified[y1][x1] == 'E' && \
		t_pos->nb_collect == t_pos->t_win1->nb_collect_tot)
			to_exit(t_pos);
		else
		{
			move_image_2(t_pos);
			t_pos->x0_image_p = t_pos->x1_image_p;
			t_pos->y0_image_p = t_pos->y1_image_p;
			t_pos->move++;
			ft_putstr_fd("move counter = ", 1);
			ft_putnbr_fd(t_pos->move, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}

void	which_image_2(t_position_image *t_pos)
{
	if (ft_strcmp(t_pos->image, "Pup") == 0)
	{
		if (!t_pos->t_list1->img_pup)
			create_img_pup(t_pos);
		t_pos->t_list1->img = t_pos->t_list1->img_pup;
	}
	if (ft_strcmp(t_pos->image, "Pdown") == 0)
	{
		if (!t_pos->t_list1->img_pdown)
			create_img_pdown(t_pos);
		t_pos->t_list1->img = t_pos->t_list1->img_pdown;
	}
	if (ft_strcmp(t_pos->image, "Pright") == 0)
	{
		if (!t_pos->t_list1->img_pright)
			create_img_pright(t_pos);
		t_pos->t_list1->img = t_pos->t_list1->img_pright;
	}
	if (ft_strcmp(t_pos->image, "Pleft") == 0)
	{
		if (!t_pos->t_list1->img_pleft)
			create_img_pleft(t_pos);
		t_pos->t_list1->img = t_pos->t_list1->img_pleft;
	}
}

void	move_image_2(t_position_image *t_pos)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;

	which_image_2(t_pos);
	x0 = t_pos->x0_image_p;
	y0 = t_pos->y0_image_p;
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_0, x0 * SIZE, y0 * SIZE);
	if (t_pos->t_win1->tab_modified[y0][x0] == 'E')
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
			t_pos->t_list1->img_e, x0 * SIZE, y0 * SIZE);
	if (t_pos->t_win1->tab_modified[y1][x1] != 'E')
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
			t_pos->t_list1->img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img, x1 * SIZE, y1 * SIZE);
}

void	to_collectible(t_position_image *t_pos)
{
//	struct timeb	*time;
	
	t_pos->move_possible = 0;
//	ftime(time);
//	t_pos->begin = time->millitm;
	t_pos->begin = time(NULL);
	mlx_loop_hook(t_pos->t_win1->mlx, anim_char, t_pos);
	t_pos->move++;
	t_pos->t_win1->tab_modified[t_pos->y1_image_p][t_pos->x1_image_p] = 0;
	t_pos->nb_collect++;
	ft_putstr_fd("move counter = ", 1);
	ft_putnbr_fd(t_pos->move, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("well done, you caught ", 1);
	ft_putnbr_fd(t_pos->nb_collect, 1);
	ft_putstr_fd(" collectible(s)\n", 1);
}

void	to_exit(t_position_image *t_pos)
{
	move_image_2(t_pos);
	t_pos->x0_image_p = t_pos->x1_image_p;
	t_pos->y0_image_p = t_pos->y1_image_p;
	t_pos->move++;
	ft_putstr_fd("move counter = ", 1);
	ft_putnbr_fd(t_pos->move, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("				!GOOD GAME!\n", 1);
	mlx_loop_end(t_pos->t_win1->mlx);
}
