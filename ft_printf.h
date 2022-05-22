/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:55:04 by ancarbon          #+#    #+#             */
/*   Updated: 2022/05/22 08:49:08 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_parse(va_list arg, const char *format);
int		ft_getformat(va_list arg, char c);

// Utils
size_t	ft_strlen(char *str);
int		i_putchar(char c);
int		i_putstr(char *str);

int		nlength(unsigned long i);
int		i_putnbr(int nb);
int		i_put_uns_nbr(unsigned int nb);

int		i_puthex(long i, char c);
int		count_hex(long x);
void	print_hex(long i, char c);

int		i_put_ptr(unsigned long p);
void	print_ptr(unsigned long p);

#endif