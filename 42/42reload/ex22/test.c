#include "ft_abs.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1;
	if (argc < 2)
		return 0;
	while (argv[i])
	{
		printf("%d\n", ABS(2));
		i++;
	}
	return 0;
}
