/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:04:21 by atuliara          #+#    #+#             */
/*   Updated: 2023/03/17 15:47:37 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = (n / 10);
		len++;
	}
	return (len);
}

static char	*ft_allocate(int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

static int	ft_minimum(int n, char *str)
{
	str[0] = '-';
	str[1] = '2';
	n = 147483648;
	return (n);
}

char	*ft_itoa(int n)
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
	if (n == -2147483648)
		n = ft_minimum(n, str);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + 48;
		n = (n / 10);
	}
	return (str);
}
