/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:36:46 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/07 13:08:42 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	i;
	char	*trimmer;

	first = 0;
	last = ft_strlen((char *)s1);
	while (s1[first] && check_set((s1[first]), set))
		first++;
	while (last > first && check_set((s1[last - 1]), set))
		last--;
	trimmer = malloc(sizeof(char) * (last - first + 1));
	if (!trimmer)
		return (NULL);
	if (trimmer == NULL)
		return (NULL);
	i = 0;
	while (first < last)
		trimmer[i++] = s1[first++];
	trimmer[i] = 0;
	return (trimmer);
}
