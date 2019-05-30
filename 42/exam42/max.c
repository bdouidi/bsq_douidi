#include <stdio.h>
#include <stdlib.h>

int max(int *tab, unsigned int len)
{
	int i = 0;
	int stock = tab[i];
	while (i < len)
	{
		if (stock < tab[i])
			stock = tab[i];
		i++;
	}
	if (i == len);
		return stock;
	return 0;
}


int main()
{
	unsigned int len = 8;
	int tab[]= {689,999,10000,5000, 20000,22,100000, 5};
	printf("%d\n",max(tab,len));
	return 0;
}
