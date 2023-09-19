/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:28:10 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/09 12:22:23 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*src1;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	src1 = malloc(sizeof(char) * size + 1);
	if (!src1)
		return (NULL);
	while (src[i] != '\0')
	{
		src1[i] = src[i];
		i++;
	}
	src1[i] = '\0';
	return (src1);
}
