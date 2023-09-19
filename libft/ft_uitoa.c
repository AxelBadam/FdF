/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:48 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/28 12:09:33 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = (n / 10);
		len++;
	}
	return (len);
}

static char	*ft_allocate(unsigned int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_counter(n);
	str = ft_allocate(len);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = 48;
	while (n > 0)
	{
		str[len--] = (n % 10) + 48;
		n = (n / 10);
	}
	return (str);
}
