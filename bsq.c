#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *read_output(void)
{
	char buffer[100];
	char *string;
	long unsigned int i;
	int j;
	
	i = 0;
	j = 0;

	read(0, &buffer, 100);
	if (!(string=(char*)malloc(sizeof(char)*(strlen(buffer)+1))))
		return 0;
	while(i < strlen(buffer))
	{
			string[j] = buffer[i];
		//	printf("%c", string[j]);
                            j++;
		i++;
	}
	return string;
}

char **str_in_tab(int k, int l)
{
	int i;
	int j;
	char *str;
	char **tab;
	int count;

	i = 0;
	j = 0;
	count = 0;
	str = read_output();
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * count +1)))
		return 0;
	i = 0;
	l = count;
	count = 0;
	while (i < l)
	{
		while (str[count] && str[count] != '\n')
			count++;
		if(!(tab[i] = (char*)malloc(sizeof(char) * count + 1)))
			return 0;
		count = 0;
		while (str[k] && str[k] != '\n')
		{
			tab[i][j] = str[k];
			k++;
			j++;
		}
		k++;
		j = 0;
		i++;
	}
	return tab;
}

int pars_tab(int k, int l)
{
	int i;
	char **tab;

	i = 0;
	tab = str_in_tab(k, l);
	while (tab[i])
	{
		printf("%ld\n", strlen(tab[i]));
		i++;
	}
	return 0;
}


int main ()
{
	int k;
	int l;
	
	k = 0;
	l = 0;
	pars_tab(k, l);
	return 0;
}
