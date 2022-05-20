/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:34:52 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/28 21:02:49 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		ret;

	// printf("1\n");
	va_start(arg, string);
	ret = ft_parse(string, arg);
	va_end(arg);
	return (ret);
}
