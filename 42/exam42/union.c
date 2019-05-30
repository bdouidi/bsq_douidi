#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_pars(char *str, char *str1)
{
	char *stock;
	int i = 0;
	int j = 0;

	if (!(stock = (char*)malloc(sizeof(char) * (strlen(str -1) + strlen(str1)))))
		return 0;
	strcat(stock, str);
	strcat(stock, str1);
	printf("* %d\n", strlen(stock));

	while (stock[i])
	{
		while (j < i)
		{
			if (stock[i] == stock[j])
				break;
			else
				j++;
		}
		if (j == i || i == 0)
			write(1, &stock[i], 1);
		i++;
		j = 0;
	}
	printf("** %d\n", strlen(stock));
	return 0;
}



int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("mauvais usage");
		return 0;
	}
	if (argv[1][0] == '\0'|| argv[2][0] == '\0')
	{
		printf("mauvais usage");
		return 0;
	}
	else
		ft_pars(argv[1], argv[2]);
	write (1, "\n", 1);
	return 0;
}
