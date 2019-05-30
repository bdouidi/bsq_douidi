#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if (argc < 2)
		return 0;
	else
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				printf("%c", argv[i][j]);
				j++;
			}
			i++;
			j = 0;
			printf("\n");
		}
	}
	return 0;
}
