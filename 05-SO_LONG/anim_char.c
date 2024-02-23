/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 20:15:09 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	anim_char(void *param)
{
	t_position_image	*t_pos4;
	time_t				end;
	
	t_pos4 = (t_position_image *)param;
	printf("begin %ld\n", t_pos4->begin);
	end = time(NULL);
	printf("end %ld\n", end);
	t_pos4 = (t_position_image *)param;
	if (difftime(end, t_pos4->begin) == 1)
		first_anim_char(t_pos4);
	if (difftime(end, t_pos4->begin) == 2)
		second_anim_char(t_pos4);
	if (difftime(end, t_pos4->begin) == 3)
		third_anim_char(t_pos4);
	if (difftime(end, t_pos4->begin) == 4)
	{
		t_pos4->x0_image_p = t_pos4->x1_image_p;
		t_pos4->y0_image_p = t_pos4->y1_image_p;
		t_pos4->move_possible = 1;
	}
	return (t_pos4->move_possible);
}

void	first_anim_char(t_position_image *t_pos)
{
	int		x0;
	int		y0;

	if (!t_pos->t_list1->img_p1)
		create_img_p1(t_pos->t_list1);
	x0 = t_pos->x0_image_p;
	y0 = t_pos->y0_image_p;
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_0, x0 * SIZE, y0 * SIZE);
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_p1, x0 * SIZE, y0 * SIZE);
}

void	second_anim_char(t_position_image *t_pos)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;

	if (!t_pos->t_list1->img_p2)
		create_img_p2(t_pos->t_list1);
	x0 = t_pos->x0_image_p;
	y0 = t_pos->y0_image_p;
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_0, x0 * SIZE, y0 * SIZE);
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_p2, x1 * SIZE, y1 * SIZE);
}

void	third_anim_char(t_position_image *t_pos)
{
	int		x1;
	int		y1;

	if (!t_pos->t_list1->img_p3)
		create_img_p3(t_pos->t_list1);
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_p3, x1 * SIZE, y1 * SIZE);
}
