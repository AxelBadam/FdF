/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:17:39 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/22 10:03:33 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*img;
	t_map	*map_info;

	img = NULL;
	if (argc == 2)
	{
		map_info = ini_map();
		read_map(argv, map_info);
		img = img_init(map_info);
		img->camera = camera_init(img);
		draw_image(map_info, img);
		controls(img);
		mlx_loop(img->mlx);
	}
	else
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", 1);
		return (1);
	}
	return (0);
}
