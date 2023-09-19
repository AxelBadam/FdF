/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:39:26 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/24 15:43:13 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putstr_mod(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_mod("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_n(int n)
{
	int		i;
	char	*str;

	str = ft_itoa(n);
	i = ft_putstr_mod(str);
	free(str);
	return (i);
}

int	ft_unsigned(unsigned int n)
{
	int		i;
	char	*str;

	str = ft_uitoa(n);
	i = ft_putstr_mod(str);
	free(str);
	return (i);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
