/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:31:53 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 17:21:57 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point start, t_point end, t_data *img)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(end.x - start.x);
	delta.y = ft_abs(end.y - start.y);
	sign.x = ft_sign(start.x, end.x);
	sign.y = ft_sign(start.y, end.y);
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		my_mlx_pixel_put(img, cur.x, cur.y, start.color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
			error[0] -= delta.y;
		if (error[1] > -delta.y)
			cur.x += sign.x;
		if (error[1] < delta.x)
			error[0] += delta.x;
		if (error[1] < delta.x)
			cur.y += sign.y;
	}
	my_mlx_pixel_put(img, cur.x, cur.y, start.color);
}

t_point	iso(t_point point)
{
	int	previous_x;
	int	previous_y;

	previous_x = point.x;
	previous_y = point.y;
	point.x = (previous_x - previous_y) * cos(0.523599);
	point.y = (previous_x + previous_y) * sin(0.523599) - point.z;
	return (point);
}

t_point	project(t_point point, t_data *img)
{
	point.x *= img->camera->zoom;
	point.y *= img->camera->zoom;
	point.z *= img->camera->zoom / img->camera->z_divisor;
	point.x -= (img->map_info->width * img->camera->zoom) / 2;
	point.y -= (img->map_info->height * img->camera->zoom) / 2;
	rotate_x(&point.y, &point.z, img->camera->alpha);
	rotate_y(&point.x, &point.z, img->camera->beta);
	rotate_z(&point.x, &point.y, img->camera->gamma);
	if (img->camera->projection == ISO)
		point = iso(point);
	point.x += WIDTH / 2 + img->camera->x_offset;
	point.y += HEIGHT / 2 + img->map_info->height * \
	img->camera->zoom / 2 + img->camera->y_offset;
	return (point);
}

t_point	new_point(int x, int y, t_map *map_info, t_data *img)
{
	t_point	point;
	int		index;

	point.x = x;
	point.y = y;
	index = get_index(x, y, map_info->width);
	point.z = map_info->coords_arr[index];
	point = project(point, img);
	point.color = map_info->colors_arr[index];
	return (point);
}

void	draw_image(t_map *map_info, t_data *img)
{
	int		x;
	int		y;

	y = 0;
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bits_per_pixel / 8));
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (x != map_info->width - 1)
				draw_line(new_point(x, y, map_info, img), \
				new_point(x + 1, y, map_info, img), img);
			if (y != map_info->height - 1)
				draw_line(new_point(x, y, map_info, img), \
				new_point(x, y + 1, map_info, img), img);
			x++;
		}
		y++;
	}
	draw_border(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	print_instructions(img);
}
