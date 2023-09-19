/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:04:20 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/23 17:39:05 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_number(char *s)
{
	if (*s == '\n')
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s != '\n' && *s != ',')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	check_format(t_map *map_info, int x, char **line_coords)
{
	int	y;

	y = 0;
	if (x != map_info->width)
		error_exit_map_info("Invalid map.\n", map_info);
	while (line_coords[y])
	{	
		if (!ft_is_number(line_coords[y]) \
		|| ft_atoi(line_coords[y]) > 10000000 || \
		ft_atoi(line_coords[y]) < -10000000)
			error_exit_map_info("Invalid map.\n", map_info);
	y++;
	}
	return (0);
}
