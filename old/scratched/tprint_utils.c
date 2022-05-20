/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tprint_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:08:43 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/28 19:57:05 by ancarbon         ###   ########.fr       */
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

int		is_flag(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')
		return (1);
	return (0);
}

void	get_flags(t_print *tab, char c)
{
	if (c == '#')
		tab->pound = 1;
	else if (c == '-')
		tab->minus = 1;
	else if (c == '+')
		tab->plus = 1;
	else if (c == ' ')
		tab->space = 1;
	else if (c == '0')
		tab->zero = 1;
	tab->i += 1;
}

size_t	ft_digits(int i)
{
	size_t	i2;

	i2 = 0;
	while(i != 0)
	{
		i /= 10;
		i2++;
	}
	return (i2);
}