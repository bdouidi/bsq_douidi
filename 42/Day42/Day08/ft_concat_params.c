#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_concat_params(int argc, char **argv)
{

	int i = 1;
	int j = 0;
	int k = 0;
	int stock = 0;
	char *str;

	if (argc < 2)
		return 0;
	while (argv[i])
	{
		stock = stock + strlen(argv[i]);
		i++;
	}
	i = 1;
	if (!( str = (char*)malloc(sizeof(char)*(stock + argc  -1))))
		return 0;
	while (k < (stock + argc -1))
	{
		if ( argv[i][j] == '\0')
		{
			j = 0;
			str[k] = '\n';
			k++;
			i++;
		}
		else
		{
			str[k] = argv[i][j];
			//printf("%c\n", str[k]);
			k++;
			j++;
		}
	}
	printf("%s", str);
	return NULL;

}

int main (int argc, char **argv)
{
	ft_concat_params(argc, argv);
	return 0;
}
