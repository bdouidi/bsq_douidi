#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void ft_rotone( char *str)
{
	int i = 0;
	while (str[i])
	{

		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'z'))
		{
			if (str[i] == 'z' || str[i] == 'Z')
			{
				if (str[i] == 'z')
					write (1, "a", 1);
				if (str[i] == 'Z')
					write (1, "A", 1);
			}
			else
			{
				str[i] = str[i] +1;
				write (1, &str[i], 1);
			}
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}
int main (int argc, char **argv)
{
	if (argc =!2 || argv[1][0] == '\0')
	{
		printf("mauvais usage");
		return 0;
	}
	else
		ft_rotone(argv[1]);
	write (1, "\n", 1);
	return 0;
}
