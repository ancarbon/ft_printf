/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:12:09 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/29 10:19:38 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_getformat(char *s, t_print *tab, va_list arg)
{
	if (s[tab->i] == 'c')
		tab->nprnt += i_putchar(va_arg(arg, int));
	else if (s[tab->i] == 's')
		tab->nprnt += i_putstr(va_arg(arg, char *));
	else if (s[tab->i] == 'd' || s[tab->i] == 'i')
		tab->nprnt += (va_arg(arg, int), 1);
	else if (s[tab->i] == 'x' || s[tab->i] == 'X')
		tab->nprnt += 0;
	else if (s[tab->i] == 'u')
		tab->nprnt += 0;
	else if (s[tab->i] == 'p' )
		tab->nprnt += 0;
	else if (s[tab->i] == '%' )
		tab->nprnt += i_putchar('%');
	tab->i += 1;
}