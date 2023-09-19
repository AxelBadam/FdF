/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:20:40 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/08 15:13:13 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*src1;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	src1 = malloc(count * size);
	if (!src1)
		return (NULL);
	ft_bzero(src1, count * size);
	return (src1);
}
