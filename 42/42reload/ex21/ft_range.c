#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ft_range(int min, int max)
{
	int *tab;
	int i = 0;

	if (!(tab = (int*)malloc(sizeof(int)*(max - min))))
		return 0;
	else
	{

		while (min <= max)
		{
			tab[i] = min;
			min++;
			i++;
		}

	}
	return tab;
}

void display_tab(int *tab, int max)
{
	int i = 0;
	while(i <= max)
	{
		printf("%d, %d\n",tab[i], i);
		i++;
	}
}

int main()
{
	int min = -10;
	int max = 45;
	int *tab;
	tab = ft_range(min, max);
	display_tab(tab, max);
	return 0;
}
