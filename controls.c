/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:57:54 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 17:29:06 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_projection(int key, t_data *img)
{
	img->camera->alpha = 0;
	img->camera->beta = 0;
	img->camera->gamma = 0;
	if (key == MAIN_PAD_I)
		img->camera->projection = ISO;
	else if (key == MAIN_PAD_P)
		img->camera->projection = TOP;
	draw_image(img->map_info, img);
}

void	zoom(int key, t_data *img)
{
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || \
		key == MOUSE_SCROLL_UP)
		img->camera->zoom++;
	else if (key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS || \
		key == MOUSE_SCROLL_DOWN)
		img->camera->zoom--;
	if (img->camera->zoom < 1)
		img->camera->zoom = 1;
	draw_image(img->map_info, img);
}

void	move(int key, t_data *img)
{
	if (key == ARROW_LEFT)
		img->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		img->camera->x_offset += 10;
	else if (key == ARROW_UP)
		img->camera->y_offset -= 10;
	else
		img->camera->y_offset += 10;
	draw_image(img->map_info, img);
}

int	key_press(int key, void *param)
{
	t_data	*img;

	img = (t_data *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || \
	key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, img);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, img);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_5 || key == MAIN_PAD_5
		|| key == NUM_PAD_6 || key == MAIN_PAD_6)
		rotate(key, img);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, img);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, img);
	return (0);
}

void	controls(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 0, key_press, img);
	mlx_hook(img->mlx_win, 17, 1L << 17, close_window_x, img);
	mlx_hook(img->mlx_win, 4, 0, mouse_press, img);
	mlx_hook(img->mlx_win, 5, 0, mouse_release, img);
	mlx_hook(img->mlx_win, 6, 0, mouse_move, img);
}
