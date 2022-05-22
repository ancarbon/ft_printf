/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:21:59 by ancarbon          #+#    #+#             */
/*   Updated: 2022/05/22 09:16:23 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getformat(va_list arg, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = i_putchar(va_arg(arg, int));
	else if (c == 's')
		ret = i_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		ret = i_putnbr(va_arg(arg, int));
	else if (c == 'u')
		ret = i_put_uns_nbr(va_arg(arg, unsigned int));
	else if (c == 'p')
		ret = i_put_ptr(va_arg(arg, unsigned long));
	else if (c == 'x' || c == 'X')
		ret = i_puthex(va_arg(arg, long), c);
	else if (c == '%')
		ret = i_putchar(c);
	return (ret);
}

int	ft_parse(va_list arg, const char *format)
{
	int	idx;
	int	ret;

	idx = 0;
	ret = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			idx++;
			ret += ft_getformat(arg, format[idx]);
		}
		else
		{
			write(1, &format[idx], 1);
			ret += 1;
		}
		idx++;
	}
	return (ret);
}
