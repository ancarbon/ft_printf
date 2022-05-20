/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:53 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/28 20:19:59 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printconversion(const char *str, t_print *tab, va_list arg)
{
	// printf("4\n");
	// printf("print conversion%zu\n", tab->i);
	if (str[tab->i] == 'c')
		convert_char(va_arg(arg, int), tab);
	else if (str[tab->i] == 's')
		// printf("entrato");
		tab->nprnt += i_putstr(va_arg(arg, char *));
	else if (str[tab->i] == 'd' || str[tab->i] == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (str[tab->i] == 'x' || str[tab->i] == 'X')
		tab->nprnt += i_putstr("ciao");
	else if (str[tab->i] == 'u')
		tab->nprnt += i_putstr("ciao");
	else if (str[tab->i] == 'p' )
		tab->nprnt += i_putchar('%');
	else if (str[tab->i] == '%' )
		tab->nprnt += i_putchar('%');
}

void	ft_getformat(const char *str, t_print *tab, va_list arg)
{
	
	// printf("3\n");
	while (is_flag(str[tab->i]))
	{
		get_flags(tab, str[tab->i]);
		// printf("minus:%d\n", tab->minus);
	}
	if (ft_isdigit(str[tab->i]) == 1)
	{
		// printf("before width%zu\n", tab->i);
		tab->width = ft_atoi(&str[tab->i]);
		// printf("%d\n", tab->width);
		// printf("%zu\n", ft_digits(tab->width));
		tab->i += ft_digits(tab->width);
		// printf("after width %zu\n", tab->i);
	}
	if (str[tab->i] == '.')
	{
		tab->precision = ft_atoi(&str[tab->i]);
		printf("%d\n", tab->precision);
		tab->i += ft_digits(tab->precision);
	}
	// printf("%d\n", tab->precision);
	// printf("%d\n", tab->width);
	// printf("%d\n", tab->minus);
	ft_printconversion(str, tab, arg);
	ft_structinit(tab);
}
