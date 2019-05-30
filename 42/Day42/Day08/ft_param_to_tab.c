#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_stock_par
{
	int size_param;
	char *str;
	char *copy;
	char **tab;
} 		t_stock_par;	

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

char **ft_split_whitespaces(char *str)
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
		if(!(tab[k]= (char*)malloc(sizeof(char) *1)))
			return 0;
		tab[k] = stock;
		//printf("valeur de k[%d]=%s, valeur de i=%d\n", k, tab[k], i);
		k++;
	}
	tab[k] = 0;
	return tab;
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	t_stock_par *p;
	int i;
	
	i = 0;
	if (!(p = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))))
		return 0;
	while (i < ac)
	{
		p[i].size_param = strlen(av[i]);
		p[i].str = av[i];
		p[i].copy = strdup(av[i]);
		p[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	p[i].str = 0;
	return p;
}


void display_tab (int ac, char **av)
{
	int i;
	int j;
	t_stock_par *p;

	i = 0;
	j = 0;
	p = ft_param_to_tab(ac,av);
	while(i < ac)
	{
		printf("%d\n", p[i].size_param);
		printf("%s\n", p[i].str);
		printf("%s\n", p[i].copy);
		while(p[i].tab[j])
		{
			printf("%s\n", p[i].tab[j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}

int main(int ac, char **av)
{


	if (ac < 1)
		return 0;
	display_tab(ac, av);
	return 0;
}
