#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int whitespace(char c, char *charset)
{
	int i;
	
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return 0;
}

int count_word(char *str, char *charset)
{
	int i;
	int j;
	int k;
	int stock;

	i = 0;
	j = 0;
	k = 0;
	stock = 0;
	while (str[k])
	{
		while (charset[j] && str[i] != charset[j])
			j++;
		if (str[i] == charset[j])
		{
			stock++;
			j = 0;
			i++;
		}
		if (charset[j] == '\0')
		{
			i = k +1;
			j = 0;
		}
		k++;
	}
	return stock;
}

int length_word(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] && !whitespace(str[i], charset))
		i++;
	return i;
}
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	
	i = 0;
	while(src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n && src[i] == '\0')
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
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

char **ft_split(char *str, char *charset)
{
	int stock;
	int i;
	int j;
	char **tab;

	i = 0;
	stock = count_word(str, charset);
	while (str[i])
		i++;
	j = 0;
	if (stock == 0)
	{
		tab = malloc(sizeof(char*) * i +1);
		tab[j] = malloc(sizeof(char) * length_word(str, charset) +1);
		tab[j] = str;
	}
	else
	{
	tab = malloc(sizeof(char*) * stock +1);
	i = 0;
	while (str[i])
	{
		if (!whitespace(str[i], charset))
		{
			tab[j] = malloc(sizeof(char) * length_word(str, charset) +1);
			tab[j]= ft_strncpy(tab[j], &str[i], length_word(&str[i], charset));
			i++;
			j++;
		}
		else
			i++;
	}
	tab[j -1] = 0;
	}
	display_tab(tab);
	return tab;
}

int main(int argc, char **argv)
{
	//char **tab;
	if (argc != 3)
		return 0;
	if (!argv[1] || !argv[2])
		return 0;
	ft_split(argv[1], argv[2]);
	return 0;
}
