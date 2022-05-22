/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:15:33 by ancarbon          #+#    #+#             */
/*   Updated: 2022/05/22 08:32:25 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(long x)
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

int	i_puthex(long i, char c)
{
	if (i == 0)
		return (i_putchar('0'));
	else
		print_hex(i, c);
	return (count_hex(i));
}

void	print_hex(long i, char c)
{
	if (i > 16)
	{
		print_hex(i / 16, c);
		print_hex(i % 16, c);
	}
	else
	{
		if (i < 10)
			i_putchar(i + 48);
		else
		{
			if (c == 'X')
				i_putchar(i + 55);
			else if (c == 'x')
				i_putchar(i + 87);
		}
	}
}