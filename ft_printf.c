/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:49:13 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/24 12:50:57 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*ft_structinit(t_print *tab)
{
	tab->format = 0;
	tab->i = 0;
	tab->len = 0;
	tab->percent = 0;
	tab->minus = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->zero = 0;
	tab->pound = 0;
	tab->sign = 0;
	tab->width = 0;
	tab->precision = 0;
	return (tab);
}
void	ft_evaluateformat(const char *string, t_print *tab, int pos)
{
	while (!ft_strchr("cspdiuxX", string[pos]))
	{
		if (string[pos] == '.')

	}
}

int	ft_printf(const char *string, ...)
{
	int		pos;
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
			tab->nprinted = write(1, &string[pos], 1);
		pos++;
	}
	va_end(tab->arg);
	return (tab->nprinted);
}

int main()
{
	ft_printf("ciao mi chiamo antonio\n");
	return (0);
}