/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:18:32 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/22 13:45:35 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_array(int fd, char **line_coords, char *line, t_map *map_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		line_coords = ft_split(line, ' ');
		free(line);
		while (line_coords[x] != NULL)
		{
			if (ft_strchr(line_coords[x], ','))
				line = (ft_strchr(line_coords[x], ',') + 1);
			else
				line = WHITE;
			map_info->colors_arr[y] = ft_atoi_base(line, 16);
			x++;
			y++;
		}
		x = 0;
		free_strsplit_arr(line_coords);
	}
}

void	read_colors(int fd, t_map *map_info)
{
	char	*line;
	char	**line_coords;

	line_coords = NULL;
	line = NULL;
	map_info->colors_arr = malloc(map_info->height * \
									map_info->width * sizeof(int));
	if (!map_info->colors_arr)
		error_exit_map_info("Malloc failed.\n", map_info);
	fill_array(fd, line_coords, line, map_info);
}

void	read_coord(int fd, t_map *map_info)
{
	int		y;
	int		x;
	char	*line;
	char	**line_coords;

	y = 0;
	x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		line_coords = ft_split(line, ' ');
		free(line);
		while (line_coords[x])
		{
			map_info->coords_arr[y] = ft_atoi(line_coords[x]);
			x++;
			y++;
		}
		check_format(map_info, x, line_coords);
		x = 0;
		free_strsplit_arr(line_coords);
	}
}

void	get_size(int fd, t_map *map_info)
{
	int		height;
	int		width;
	char	*line;
	char	**line_coords;

	height = 0;
	width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		if (!map_info->width)
		{
			line_coords = ft_split(line, ' ');
			while (line_coords[width])
				width++;
			map_info->width = width;
			free_strsplit_arr(line_coords);
		}
		free(line);
	}
	map_info->height = height;
}

void	read_map(char **argv, t_map *map_info)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit_map_info("Error opening file.\n", map_info);
	get_size(fd, map_info);
	close(fd);
	if (map_info->height == 0)
		error_exit_map_info("Invalid map.\n", map_info);
	map_info->coords_arr = malloc((map_info->height) * \
									(map_info->width) * sizeof(int));
	if (!map_info->coords_arr)
		error_exit_map_info("Malloc failed.\n", map_info);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit_map_info("Error opening file.\n", map_info);
	read_coord(fd, map_info);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit_map_info("Error opening file.\n", map_info);
	read_colors(fd, map_info);
	close(fd);
}
