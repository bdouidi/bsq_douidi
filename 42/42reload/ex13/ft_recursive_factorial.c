#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factoriel(int nb)
{
	if (nb < 0)
		return 0;
	else if( nb == 1 || nb == 0)
		return 1;
	//printf("%d\n", nb);
	return nb * factoriel (nb - 1);
}

int main ()
{
	int i = 14;
	printf("%d\n",factoriel(i));
	return 0;
}
