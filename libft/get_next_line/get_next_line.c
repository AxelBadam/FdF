/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:34:13 by atuliara          #+#    #+#             */
/*   Updated: 2023/02/20 16:29:26 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stat(char *stat_str)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	if (!stat_str[i])
	{
		free(stat_str);
		return (NULL);
	}
	str = malloc((sizeof(char)) * ft_strlen_g(stat_str) - i + 2);
	if (!str)
		return (NULL);
	i++;
	while (stat_str[i])
		str[j++] = stat_str[i++];
	str[j] = '\0';
	free(stat_str);
	return (str);
}

char	*get_line(char *stat_str)
{
	int		i;
	char	*line;

	i = 0;
	if (stat_str[i] == 0)
		return (NULL);
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
	{
		line[i] = stat_str[i];
		i++;
	}
	if (stat_str[i] == '\n')
	{
		line[i] = stat_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_to_stat(int fd, char *stat_str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_g(stat_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stat_str = ft_strjoin_g(stat_str, buffer);
	}
	free(buffer);
	return (stat_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_str = ft_read_to_stat(fd, stat_str);
	if (!stat_str)
		return (NULL);
	line = get_line(stat_str);
	stat_str = new_stat(stat_str);
	return (line);
}
