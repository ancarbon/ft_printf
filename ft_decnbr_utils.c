/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:56:41 by ancarbon          #+#    #+#             */
/*   Updated: 2022/05/21 23:22:28 by ancarbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	nlength(unsigned long i)
{
	int	l;

	l = 0;
	while (i > 0)
	{
		i /= 10;
		l++;
	}
	return (l);
}

int	i_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		i += i_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		i += i_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb <= 9)
		i += i_putchar(nb + 48);
	return (i);
}

int	i_put_uns_nbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 4294967295)
		return (write(1, "4294967295", 10));
	if (nb < 0)
		return (i_putnbr(4294967295 - nb));
	if (nb >= 0)
	{
		if (nb > 9)
			i += i_putnbr(nb / 10);
		i += i_putchar(nb % 10 +48);
	}
	return (i);
}
