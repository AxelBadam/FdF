/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:28:12 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/20 16:47:01 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (x *= -1);
	else
		return (x);
}

int	get_height(char **line)
{
	int	i;

	i = 0;
	while (ft_strchr(*line, '\n') != NULL)
		i++;
	return (i);
}

int	get_width(char **line)
{
	int	i;

	i = 0;
	while (ft_strchr(*line, '\n') != NULL)
		i++;
	return (i);
}

int	close_window_x(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}
