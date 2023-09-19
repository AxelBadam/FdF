/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:05:03 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 12:33:58 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_sign(int f, int s)
{
	if (f < s)
		return (1);
	if (f > s)
		return (-1);
	else
		return (0);
}

void	flatten(int key, t_data *img)
{
	if (key == MAIN_PAD_LESS)
		img->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_MORE)
		img->camera->z_divisor += 0.1;
	if (img->camera->z_divisor < 0.1)
		img->camera->z_divisor = 0.1;
	else if (img->camera->z_divisor > 10)
		img->camera->z_divisor = 10;
	draw_image(img->map_info, img);
}

void	draw_border(t_data *img)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 115;
	start.z = 0;
	start.color = COLOR_WHITE;
	end.x = 260;
	end.y = 115;
	end.z = 0;
	end.color = 0;
	draw_thick_line(start, end, 2, img);
	start.x = 260;
	start.y = 0;
	start.z = 0;
	end.x = 260;
	end.y = 115;
	end.z = 0;
	draw_thick_line(start, end, 2, img);
}
