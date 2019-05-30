#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_sqrt(int nb)
{
	int i = 1;
	int stock = 0;
	while (i < nb)
	{
		stock = i * i;
		if (stock == nb)
			return i;
		i++;
	}
	return 0;
}

int main ()
{
	int i = 1444;
	printf("%d\n",ft_sqrt(i));
	return 0;
}
