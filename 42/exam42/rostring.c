#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ft_rost(char *str)
{
	int i = strlen(str) -1;
	int j;
	int k;
	int l = 0;
	int m;
	while (str[i] == ' ')
		i--;

	if (i < 0)
		return 0;
	j = i;
	while (str[j] != ' ' && str[j-1] != ' ' && j != 0)
		j--;
	k = j;
	while (j <= i)
	{
		write(1, &str[j], 1);
		j++;
	}
	if(!(k == 0 && i == strlen(str) -1))
	{
		while (str[l] == ' ')
			l++;
		if (l < k)
		{
			m = k -1;
			while (str[m] == ' ')
				m--;
			m++;
			write (1, " ", 1);
			while(l < k)
			{	
				while (str[l] == ' ')
				{
					l++;
				}
				while (str[l] != ' ' && l < k)
				{
					write(1, &str[l], 1);
					l++;
				}
				if (l == m)
					return 0;
				if (str[l] == ' ' && str[l-1] != ' '  && l < k)
					write(1, " ",1);
				l++;
			}
		}
		else
			return 0;
	}
}

int main (int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("mauvais usage\n");
		return 0;
	}
	else 
		ft_rost(argv[1]);
	write(1, "\n", 1);
	return 0;
}
