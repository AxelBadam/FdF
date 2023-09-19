/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:30:33 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/07 13:12:45 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	k;

	if (!dst && !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	i = ft_strlen(dst);
	s = ft_strlen((char *)src);
	k = i;
	if (dstsize < i)
		return (dstsize + s);
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + s);
}
