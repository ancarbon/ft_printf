#include "libft.h"
#include "ft_printf.h"

//t_print	*modifiers(const char *string, t_print *tab, )

int	i_putchar(char c)
{
	return (write(1, &c, 1));
}

int	i_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		i_putchar(s[i]);
	return (i);
}

int	i_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i = i_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(48 + n % 10, fd);
	}
	
}