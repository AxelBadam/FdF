/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:35:40 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 17:29:57 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
	i = (y * img->line_length + x * (img->bits_per_pixel / 8));
	img->addr[i] = color;
	img->addr[++i] = color >> 8;
	img->addr[++i] = color >> 16;
	}
}

t_point	assign_point(int x, int y, int z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

void	print_instructions(t_data *img)
{
	mlx_string_put(img->mlx, img->mlx_win, 3, 1, \
	COLOR_WHITE, "ZOOM: scroll | +/-");
	mlx_string_put(img->mlx, img->mlx_win, 3, 15, \
	COLOR_WHITE, "TRANSLATE: arrows");
	mlx_string_put(img->mlx, img->mlx_win, 3, 30, \
	COLOR_WHITE, "MOVE: mouse press & move");
	mlx_string_put(img->mlx, img->mlx_win, 3, 45, \
	COLOR_WHITE, "ROTATE: 1/3/4/6/2/5");
	mlx_string_put(img->mlx, img->mlx_win, 3, 60, \
	COLOR_WHITE, "FLATTEN: < / >");
	mlx_string_put(img->mlx, img->mlx_win, 3, 75, \
	COLOR_WHITE, "PROJECTION: P = top");
	mlx_string_put(img->mlx, img->mlx_win, 3, 90, \
	COLOR_WHITE, "PROJECTION: I = isometric");
}

void	draw_thick_line(t_point start, t_point end, int thickness, t_data *img)
{
	int		offset;
	t_point	thick_end;
	t_point	thick_start;
	int		dy;
	int		dx;

	offset = thickness / 2;
	dx = -offset;
	while (dx <= offset)
	{
		dy = -offset;
		while (dy <= offset)
		{
			thick_end = assign_point(end.x + dx, end.y + dy, end.z, end.color);
			thick_start = assign_point(start.x + dx, start.y + dy, start.z, \
								start.color);
			draw_line(thick_start, thick_end, img);
			dy++;
		}
		dx++;
	}
}
