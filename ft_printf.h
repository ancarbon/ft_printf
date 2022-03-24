/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:28 by ancarbon          #+#    #+#             */
/*   Updated: 2022/03/24 11:17:45 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft.h"

typedef struct s_print
{
	va_list	arg;

	char	*format;

	int		nprinted;

	int		i;
	int		len;

	int		percent;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		pound;
	int		sign;

	int		width;
	int		precision;

}	t_print;


int	ft_printf(const char *string, ...);

#endif