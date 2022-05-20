/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:29:28 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/29 10:11:48 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_parse(const char *string, va_list arg)
{
	// printf("2\n");
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab->i = 0;
	tab->nprnt = 0;
	while(string[tab->i])
	{
		if (string[tab->i] == '%')
		{
			tab->i++;
			ft_getformat(string, tab, arg);
		}
		else
		{
			tab->nprnt += write(1, &string[tab->i], 1);
			tab->i++;
		}
	}
	return (tab->nprnt);
}