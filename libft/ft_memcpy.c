/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:09 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/09 12:24:33 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr;
	const char	*ptr2;

	if (!dst && !src)
		return (0);
	ptr = dst;
	ptr2 = src;
	while (n-- > 0)
		*ptr++ = *ptr2++;
	return (dst);
}
