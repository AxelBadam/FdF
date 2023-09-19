/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:28:52 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/07 15:59:50 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_allocate(int i, int j)
{
	char	*new;

	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	new[i + j] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	new = ft_allocate(i, j);
	if (!new)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j] != '\0')
	{
		new[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new);
}
