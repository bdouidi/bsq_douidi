#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ft_lw( char *str)
{
	int i = strlen(str) -1;
	int j;

	while (str[i] == ' ' || str[i] == '\t' && i >= 0)
		i--;
	if (i < 0)
		return 0;	
	j = i;
	while(str[j] != ' ' && str[j] != '\t' && str[j-1] != ' ' && str[j-1] != '\t' && j > 0)
		j--;
	while (j<= i)
	{
		write(1, &str[j], 1);
		j++;
	}
	return 0;
}


int main(int argc, char **argv)
{ 
	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("mauvais usage\n");
		return 0;
	}
	else
		ft_lw(argv[1]);
	write(1, "\n",1);
	return 0;
}


