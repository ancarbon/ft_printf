/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:49:13 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/26 21:49:46 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_structinit(t_print *tab)
{
	tab->minus = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->pound = 0;
	tab->sign = 0;
	tab->width = 0;
	tab->precision = 0;
	return (tab);
}

int	ft_flags(const char *string, t_print *tab, int pos)
{
	int	i;

	i = 0;
	while (!ft_strchr("cspdiuxX", string[pos]))
	{
		if (string[pos] == '.')
			tab->dot = 1;
		else if (string[pos] == '-')
			tab->minus = 1;
		else if (string[pos] == '+')
			tab->plus = 1;
		else if (string[pos] == '#')
			tab->pound = 1;
		else if (string[pos] == ' ')
			tab->space = 1;
		else if (string[pos] == '0')
			tab->zero = 1;
		else if (string[pos + 1] == '.' && string[pos] >= 48
			&& string[pos] <= 57)
			tab->width = ft_itoa(string[pos]);
		else if (string[pos - 1] == '.' && string[pos] >= 48
			&& string[pos] <= 57)
			tab->precision = ft_itoa(string[pos]);
		i++;
	}
	return (i);
}

int	ft_conversion(char c, t_print *tab, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'i' || c == 'd')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x' || c == 'X')
		return (1);
	else if (c == '%')
		write(1, '%', 1);
	return (i);
}

int	ft_evaluateformat(const char *string, t_print *tab, int pos, va_list arg)
{
	int	i;

	i = 0;
	if (!ft_strchr("cspdiuxX", string[pos]))
		ft_flags(string, tab, pos);
	else if (ft_strchr("cspdiuxX", string[pos]))
		ft_conversion(string[pos], tab, arg);
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int		pos;
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_structinit(tab);
	va_start(tab->arg, string);
	pos = 0;
	while (string[pos])
	{
		if (string[pos] == '%')
			break ;
		else
			tab->nprinted += write(1, &string[pos], 1);
		pos++;
	}
	va_end(tab->arg);
	return (tab->nprinted);
}

int main(void)
{
	ft_printf("ciao mi chiamo antonio\n");
	return (0);
}
