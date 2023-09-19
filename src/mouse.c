/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:47:33 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/21 17:29:28 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*img;

	(void)x;
	(void)y;
	img = (t_data *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, img);
	else if (button == MOUSE_LEFT_BUTTON)
		img->mouse->is_pressed = true;
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*img;

	(void)x;
	(void)y;
	(void)button;
	img = (t_data *)param;
	img->mouse->is_pressed = false;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*img;

	img = (t_data *)param;
	img->mouse->previous_x = img->mouse->x;
	img->mouse->previous_y = img->mouse->y;
	img->mouse->x = x;
	img->mouse->y = y;
	if (img->mouse->is_pressed)
	{
		img->camera->beta += (x - img->mouse->previous_x) * 0.002;
		img->camera->alpha += (y - img->mouse->previous_y) * 0.002;
		draw_image(img->map_info, img);
	}
	return (0);
}
