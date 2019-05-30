#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_expand_str(char *str, int *trklm)
{
	
	if (*str != ' ' && *str != '\t')
	{
		write(1, str, 1);
		*trklm++;
	}
	else if (*(str+1) != ' ' && *(str+1) != '\t' && *(str+1) != '\0' && *trklm != 0)
		write(1, "   ", 3);
	while (*str != '\0')
	 	ft_expand_str(str+1, trklm);
}

int main(int argc, char **argv)
{
	int trklm = 0;
	if (!(argc == 2))
	{
		printf("mauvaise usage 1\n");
		return 0;
	}
	if (argv[1][0] == '\0')
	{
		printf("\n");
		return 0;
	}
	else 
		ft_expand_str(argv[1], &trklm);
	return 0;
}
	
