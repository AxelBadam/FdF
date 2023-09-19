/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:00:00 by ajordan-          #+#    #+#             */
/*   Updated: 2022/11/25 13:25:19 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_putstr_mod(char *str);
int		ft_print_p(unsigned long long ptr);
int		ft_print_n(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printpercent(void);
int		ft_unsigned(unsigned int n);
int		ft_hex(unsigned int n, const char format);
char	*ft_uitoa(unsigned int n);

#endif
