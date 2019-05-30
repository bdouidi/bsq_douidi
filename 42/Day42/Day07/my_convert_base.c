#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_atoi_base(char *nbr, char *base_from)
{
	int i = 0;
	int j = 0;
	int sign = 1;
	int res = 0;
	int size_base = 0;

	while (base_from[size_base])
		size_base++;
	while (nbr[i] && (nbr[i] == ' '||nbr[i] == '\t'||nbr[i] == '\v'||nbr[i] == '\n'||nbr[i] == '\f'||nbr[i] == '\r'))
		i++;
	if (nbr[i] == '-')
		sign = -1;
	while (nbr[i] && (!(nbr[i] == ' ' || nbr[i] == '\t'|| nbr[i] == '\v' || nbr[i] == '\n' || nbr[i] == '\f'|| nbr[i] == '\r')))
	{	
		while (base_from[j] && base_from[j] != nbr[i])
			j++;
		res = res * (size_base) + j;
		i++;
		j = 0;
	}
	//printf("%d\n", res * sign);
	return (res * sign);
}

char *convert_base_ten_to_base_to (int number, char *base_from, char *base_to, char *nbr)
{
	int stock = ft_atoi_base(nbr, base_from);
	int i = 0;
	int tmp = 0;
	char *tab;
	int j = 0;

	while (base_to[i])
		i++;
	while (stock != 0)
	{
		stock = stock / i;
		j++;
	}
	if (!(tab = (char*)malloc(sizeof(char) * j)))
		return 0;
	if ( number > 0)
		convert_base_ten_to_base_to (number /i, base_from, base_to, nbr);
	tab[tmp] = base_to[number % i];
	if (number <= 0)
		tab[tmp] = '\0';
	tmp++;
	return tab;
}
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i = 0;
	char *tab;
	int number;

	if (!nbr || !base_from || !base_to)
		return 0;
	number = ft_atoi_base(nbr, base_from);
	tab = convert_base_ten_to_base_to(number, base_from, base_to, nbr);
	return 0;
}

int main (int argc, char **argv)
{
	ft_convert_base(argv[1], argv[2], argv[3]);
	return 0;
}
