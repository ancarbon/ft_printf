/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:12:24 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/28 20:17:23 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(char c, t_print *tab)
{
	// printf("minus:%d\n", tab->minus);
	// printf("width:%d\n", tab->width);
	if (tab->minus)
	{
		tab->nprnt = i_putchar(c);
		while (--tab->width > 0)
			tab->nprnt += i_putchar(' ');
	}
	else
	{
		while (--tab->width > 0)
			tab->nprnt += i_putchar(' ');
		tab->nprnt = i_putchar(c);
	}
	tab->i += 1;
}

// int main(void)
// {
// 	t_print *tab;

// 	tab = (t_print *)malloc(sizeof(t_print));
// 	tab->minus = 1;
// 	tab->width = 3;
// 	i_putchar(':');
// 	convert_char('c', tab);
// 	i_putchar(':');
// 	return (0);
// }