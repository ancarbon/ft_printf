/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:28 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/28 20:13:08 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft.h"

typedef struct s_print
{
	size_t	i;
	size_t	nprnt;
	
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		pound;
	int		sign;
	int		dot;

	int		width;
	int		precision;

}	t_print;


int		ft_printf(const char *string, ...);
int		ft_parse(const char *string, va_list arg);
void	ft_getformat(const char *str, t_print *tab, va_list arg);

t_print	*ft_structinit(t_print *tab);
void	get_flags(t_print *tab, char c);
int		is_flag(char c);
size_t	ft_digits(int i);

//conversions
void	ft_printconversion(const char *str, t_print *tab, va_list arg);
void	convert_char(char c, t_print *tab);
//ft_printf_utils
int	i_putchar(char c);
int	i_putstr(char *c);
#endif