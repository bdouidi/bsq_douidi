#include "do_op.h"

int ft_add(char **av)
{

	return ft_atoi(av[1]) + ft_atoi(av[3]);
}

int ft_sou(char **av)
{
	return ft_atoi(av[1]) - ft_atoi(av[3]);
}

int ft_mul(char **av)
{
	return ft_atoi(av[1]) * ft_atoi(av[3]);
}

int ft_div(char **av)
{
	return ft_atoi(av[1]) / ft_atoi(av[3]);
}

int ft_mod(char **av)
{
	return ft_atoi(av[1]) % ft_atoi(av[3]);
}

