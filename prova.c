#include "ft_printf.h"

int main(void)
{
	// char s[20] = "ntonio";
	// char c = 'a';
	// int a = -42;
	int i = 0;
	int e = 0;
	
	e = printf("or :%p\n", (void *)-1);
	i = ft_printf("ft :%p\n", (void *)-1);
	printf("ft:%d - or:%d\n", i, e);
	return (0);
}