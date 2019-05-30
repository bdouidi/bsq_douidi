#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *ft_rrange(int start, int end)
{
	int *tab;
	int i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * (end - start) + 1)))
		return 0;
	while(end >= start)
	{
		tab[i] = end;
		printf ("%d valeur de	tab[%d] \n", tab[i], i );
		end --;
		i++;
	}
		printf("%d\n",sizeof(tab));
	return tab;
}


int main ()
{
	int s = -6;
	int e = 10;
	ft_rrange(s, e);
	return 0;
}
