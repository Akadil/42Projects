#include "../printf/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	int	my_len;
	int	right_len;
	char	*s;

	my_len = 0;
	right_len = 0;
	s = (char *)malloc(1);
	if (!s)
		return (0);
	s[0] = '\0';

	my_len += ft_printf("Testing null string: %s\n", s);
	my_len += ft_printf("Testing pointer to null %p", s);

	ft_printf("\n    -------     \n");

	right_len += printf("Testing null string: %s\n", NULL);
	right_len += printf("Testing pointer to null %p", 0);
	
	/*
	void	*ptr;
	char	c;

	c = 0;
	ptr = &c;

	printf("\n\n Let's start!!! \n\n");
	my_len += ft_printf("Hel%co %s! %d times out of %i\n", 'l', "akadil", 2, INT_MIN);
	my_len += ft_printf("Ascii of %u. My name is %p\n", 10, ptr);
	my_len += ft_printf("Hex of 1234 is %x and %X, PERCENT SIGN is %%", -1, 1234);

	ft_printf("\n\n");

	right_len += printf("Hel%co %s! %d times out of %i\n", 'l', "akadil", 2, INT_MIN);
        right_len += printf("Ascii of %u. My name is %p\n", 10, ptr);
        right_len += printf("Hex of 1234 is %x and %X. PERCENT SIGN is %%", -1, 1234);
	*/

	printf("\n\nMy_len: %d, Right_len: %d\n\n", my_len, right_len);
	return (0);
}
