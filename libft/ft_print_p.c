/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:44:03 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/30 11:53:05 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_p_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_p(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_put_p(nb / 16);
		ft_put_p(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_print_p(unsigned long long p)
{
	int	print_length;

	print_length = 0;
	write(1, "0x", 2);
	print_length += 2;
	if (p == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_p(p);
		print_length += ft_p_len(p);
	}
	return (print_length);
}
