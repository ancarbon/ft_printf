#include "ft_printf.h"

int main(void)
{
	char s[20] = "ntonio";
	char c = 'a';
	int a = -42;
	int i = 0;
	int e = 0;
	i = ft_printf("ft :ciao mi chiamo %c%p %X\n", c, s, a);
	e = printf("or :ciao mi chiamo %c%p %X\n", c, s, a);
	printf("ft:%d - or:%d\n", i, e);
	return (0);
}