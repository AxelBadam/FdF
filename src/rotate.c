/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:31:00 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 12:36:00 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	rotate(int key, t_data *img)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		img->camera->alpha += 0.05;
	else if (key == NUM_PAD_5 || key == MAIN_PAD_5)
		img->camera->alpha -= 0.05;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1)
		img->camera->beta -= 0.05;
	else if (key == NUM_PAD_3 || key == MAIN_PAD_3)
		img->camera->beta += 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		img->camera->gamma -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		img->camera->gamma += 0.05;
	draw_image(img->map_info, img);
}
