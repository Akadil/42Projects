#include <stdarg.h>
#include <stdio.h>

int	AddNumbers(int n, ...)
{
	int	sum;
	int	i;
	int	container;
	
	i = 0;
	sum = 0;
	va_list	ptr;
	va_start(ptr, n);
	while (i < n)
	{
		container = va_arg(ptr, int);
		printf("\nNum:%d\n", container);
		sum += container;
		i++;
	}
	va_end(ptr);
	return (sum);
}

int	LargestNumber(int n, ...)
{
	va_list	ptr;
	int	max;
	int	i;
	int	temp;

	i = 0;
	va_start(ptr, n);
	max = va_arg(ptr, int);
	while (i < n - 1)
	{
		temp = va_arg(ptr, int);
		if (temp > max)
			max = temp;
		i++;
	}
	va_end(ptr);
	return (max);
}

int	special(char *s, ...)
{
	va_list	ptr;
	int	max;
	int	i;
	int	temp;

	i = 0;
	va_start(ptr, s);
	max = va_arg(ptr, int);
	while (i < 3)
	{
		printf("\n-%s-\n", s);
		temp = va_arg(ptr, int);
		if (temp < max)
			max = temp;
		i++;
	}
	va_end(ptr);
	return (max);
}

void	ft_strlen(char *s)
{
	int	i;

	i = 0;
	printf("%s", s);
	while (s[i])
	{
		printf("%c", s[i]);
		i++;
	}
	printf("\n\n---------\n\n");


}

void	test_string(char *s, ...)
{
	va_list	ptr;
	int	i;

	va_start(ptr, s);
	i = 0;
	while (i < 3)
	{
		ft_strlen(va_arg(ptr, char *));
		i++;
	}
	va_end(ptr);
}

int	main(void)
{
	printf("\n\n Variadic functions: \n\n");
 
	// Variable number of argument
	/*
	printf("\n 1 + 2 = %d ", AddNumbers(2, 1, 2));
 	printf("\n 3 + 4 + 5 = %d ", AddNumbers(3, 3, 4, 5));
	printf("\n 6 + 7 + 8 + 9 = %d ", AddNumbers(4, 6, 7, 8, 9));

	printf("\n");

	printf("\n 1 + 2 = %d ", LargestNumber(2, 1, 2));
        printf("\n 3 + 4 + 5 = %d ", LargestNumber(3, 3, 4, 5));
        printf("\n 6 + 7 + 8 + 9 = %d ", LargestNumber(4, 6, 7, 8, 9));

	printf("\n");

	printf("\n (3, 5, 2, 4) is %d", special("AkAdIl", 3, 5, 2, 4));
	printf("\n (3, 5, 2, 4) is %d", special("AkAdIl", 3, 5, 2, 4));

	printf("\n");
*/
	//test_string("Akadil", "Kalimoldayev", "Sabituly", "Kazakh");
	printf("%u", -20);
	
	return (0);
}
