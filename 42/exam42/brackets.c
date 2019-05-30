#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_sizetab(char *str)
{
	int i = 0;
	int count= 0;
	while (str[i])
	{
		if (str[i] == '{' ||str[i] == '}' ||str[i] == '[' ||str[i] == ']' ||str[i] == '(' ||str[i] == ')' )
			count ++;
		i++;
	}
	if (count == 0)
	{
		printf("OK\n");
		return 0;
	}
	return count;
}

int ft_bracket(char *str)
{
	int count = ft_sizetab(str);
	char tab[count];
	int i= 0;
	int j = 0;
	while (str[i])
	{
		if (str[i] == '{' ||str[i] == '}' ||str[i] == '[' ||str[i] == ']' ||str[i] == '(' ||str[i] == ')')
		{
			tab[j] = str[i];
			j++;
		}
		i++;
	}
	if(!(tab[j-1] == '}' || tab[j-1] == ']'|| tab[j-1] == ')'))
	{
		printf("error0\n");
		return 0;
	}
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] == '{')
		{
			while (tab[j] != '}' && tab[j] != '\0')	
				j++;
			if ( tab[j] == '}')
				tab[j] = '*';
			if (tab[j] == '\0')
			{
				printf("error1");
				return 0;
			}
		}
		if (tab[i] == '[')
		{
			while (tab[j] != ']' && tab[j] != '{' && tab[j] != '}' && tab[j] != '\0')
				j++;
			if (tab[j] == ']')
				tab[j] = '*';
			if (tab[j] == '{' || tab[j] == '}' || tab[j] == '\0')
			{
				printf("error2");
				return 0;
			}
		}
		if (tab[i] == '(')
		{
			while (tab[j] != ')' && tab[j] != '[' && tab[j] != ']' && tab[j] != '{' && tab[j] != '}' && tab[j] != '\0')
				j++;
			if (tab[j] == ')')
				tab[j] = '*';
			if (tab[j] == '['||  tab[j] == ']'|| tab[j] == '{' || tab[j] == '}' || tab[j] == '\0')
			{
				printf ("error3\n");
				return 0;
			}
		}
		if (tab[i] == ')' || tab[i] == ']' || tab[i] == '}')
		{
			printf("error4\n");
			return 0;
		}
		i++;
		j = i;
	}
	if (tab[i] == '\0')
	{
		printf("OK <3\n");
		return 0;
	}
	return 0;
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		printf("error\n");
		return 0;
	}
	else 
		ft_bracket(argv[1]);
	//write(1,"\n", 1);
	return 0;
}
