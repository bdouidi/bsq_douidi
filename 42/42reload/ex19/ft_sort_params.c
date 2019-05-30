#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	char *c;
	if (argc < 2)
		return 0;
	else
	{
		while(argv[i])
		{
			if (argv[i + 1])
			{
				if (strcmp(argv[i],argv[i + 1]) > 0)
				{
					c = argv[i + 1];
					argv[i + 1] = argv[i];
					argv[i] = c;
					i = 0;
				}
			}
				i++;
		}
		i = 1;
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

