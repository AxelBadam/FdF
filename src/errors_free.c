/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:46:21 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/22 10:07:54 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_all(t_data *img)
{
	if (img->camera)
		free(img->camera);
	if (img->map_info)
	{
		if (img->map_info->coords_arr)
			free(img->map_info->coords_arr);
		if (img->map_info->colors_arr)
			free(img->map_info->colors_arr);
		free(img->map_info);
	}
	if (img->mouse)
		free(img->mouse);
	if (img)
		free(img);
}

void	error_exit(char *str, t_data *img)
{
	free_all(img);
	ft_putstr_fd(str, 2);
	exit (1);
}

void	free_strsplit_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_all_map_info(t_map *map_info)
{
	if (map_info)
	{
		if (map_info->coords_arr)
			free(map_info->coords_arr);
		if (map_info->colors_arr)
			free(map_info->colors_arr);
		free(map_info);
	}
}

void	error_exit_map_info(char *str, t_map *map_info)
{
	free_all_map_info(map_info);
	ft_putstr_fd(str, 2);
	exit (1);
}
