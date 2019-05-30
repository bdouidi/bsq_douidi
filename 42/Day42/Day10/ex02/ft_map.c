#include <stdio.h>
#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *array;

	i = 0;
	if (!(array = (int*)malloc(sizeof(int)* length)))
		return 0;
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return array;
}
