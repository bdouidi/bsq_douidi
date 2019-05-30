#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char temp;
	while(str[i])
		i++;
	i--;
	while (j < i)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return str;
}

int main (int argc, char **argv)
{
	if (!(argc == 2))
	{
		printf("mauvaise usage\n");
		return 0;
	}
	printf("%s\n",ft_strrev(argv[1]));
	return 0;
}


		
