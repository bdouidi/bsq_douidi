#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_word(char *str)
{
	int i = 0;
	int stock = 0;

	while (str[i])
	{
		while ((str[i] == '\n'|| str[i] == '\t' || str[i] == ' ') && str[i])
			i++;
		stock++;
		while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
			i++;
		//printf("%d\n", stock);
	}
	return stock;
}

char **malloc_word(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *stock;
	int start = 0;
	int end = 0;
	char **tab;

	if(!(tab = (char**)malloc(sizeof(char*) *(count_word(str) +1))))
		return 0;
	while (str[i])
	{
		while ((str[i] == '\n'|| str[i] == '\t' || str[i] == ' ') && str[i])
			i++;
		start = i;
		while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
			i++;
		end = i;
		if(!(stock = (char*)malloc(sizeof(char) *(end- start))))
			return 0;
		while(start <= end)
		{
			stock[j] = str[start];
			start++;
			j++;
		}
		j = 0;
		if(!(tab[k]= (char*)malloc(sizeof(char) *(end - start +1))))
			return 0;
		tab[k] = stock;
		//printf("valeur de k[%d]=%s, valeur de i=%d\n", k, tab[k], i);
		k++;
	}
	return tab;
}

char **sort_tab(char *str)
{
	char **tab;
	int i;
	char *stock;

	tab = malloc_word(str);
	i = 0;
	while (tab[i])
	{
		if (tab[i+1] && strcmp(tab[i], tab[i+1]) > 0)
		{
			stock = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = stock;
			i = 0;
		}
		else
			i++;
	}
	return tab;

}

void display_tab(char **tab)
{
	int i = 0;
	int j = 0;
	while (tab[i])
	{
		while(tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}
int main(int argc, char **argv)
{
	char **tab = sort_tab(argv[1]);

	if (argc < 2)
		return 0;
	else
		//ft_split_whitespaces(argv[1]);
		//count_word(argv[1]);
		//if (malloc_word(argv[1]))
		display_tab(tab);
	return 0;
}
