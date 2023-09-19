/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:13 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 16:46:58 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ini_map(void)
{
	t_map	*map_info;

	map_info = (t_map *)malloc(sizeof(t_map));
	if (!map_info)
	{
		write(2, "Malloc error\n", 13);
		exit (1);
	}
	map_info->width = 0;
	map_info->height = 0;
	map_info->coords_arr = NULL;
	map_info->colors_arr = NULL;
	return (map_info);
}

t_data	*img_init(t_map *map_info)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		error_exit_map_info("Malloc error\n", map_info);
	img->mlx = mlx_init();
	if (!img->mlx)
		error_exit("Error initializing mlx\n", img);
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "FdF");
	if (!img->mlx_win)
		error_exit("Error creating window\n", img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
		error_exit("Error creating new image\n", img);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	img->map_info = map_info;
	img->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!img->mouse)
		error_exit("Malloc error(mouse)\n", img);
	return (img);
}

t_camera	*camera_init(t_data *img)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		error_exit("Malloc error\n", img);
	camera->zoom = ft_min((WIDTH) / img->map_info->width / 2, \
	HEIGHT / img->map_info->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
