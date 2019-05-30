#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_iterative_factorial(int nb)
{
	int i = 1;
	int stock = 1;
	
	if (nb == 0)
		printf("1\n");
	while ( i <= nb)
	{
		stock = i * stock;
		i++;
		printf("%d\n", stock);
	}
	return 0;
}

int main()
{
	int i = 10;
	ft_iterative_factorial(i);
	return 0;
}
