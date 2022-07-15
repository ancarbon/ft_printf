/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:38:41 by ancarbon          #+#    #+#             */
/*   Updated: 2022/07/15 13:10:58 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(unsigned long long x)
{
	int	i;

	i = 0;
	while (x != 0)
	{
		x /= 16;
		i++;
	}
	return (i);
}

int	i_put_ptr(unsigned long long p)
{
	i_putstr("0x");
	if (p == 0)
		return (i_putchar('0') + 2);
	else
		print_ptr(p);
	return (count_ptr(p) + 2);
}

void	print_ptr(unsigned long long p)
{
	if (p >= 16)
	{
		print_ptr(p / 16);
		print_ptr(p % 16);
	}
	else
	{
		if (p <= 9)
			i_putchar(p + 48);
		else
			i_putchar(p - 10 + 'a');
	}
}
