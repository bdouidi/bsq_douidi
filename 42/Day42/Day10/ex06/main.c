#include "do_op.h"
#include <stdio.h>
#include <string.h>

int do_op(char **av)
{
	int i;
	t_cal tab[5];

	i = 0;
	tab[0].op = "+";
	tab[0].f = ft_add;
	tab[1].op = "-";
	tab[1].f = ft_sou;
	tab[2].op = "*";
	tab[2].f = ft_mul;
	tab[3].op = "/";
	tab[3].f = ft_div;
	tab[4].op = "%";
	tab[4].f = ft_mod;
	while (i < 5)
	{
		//printf("%d ici\n", tab[2].f(av));

		if(strcmp(av[2],tab[i].op) == 0)
		{
			return(tab[i].f(av));
		}
		i++;
	}
	return 0;

}

int main (int ac, char **av)
{
	if (ac != 4)
		return 0;
	ft_putnbr(do_op(av));
	printf("\n");
	return 0;

}
