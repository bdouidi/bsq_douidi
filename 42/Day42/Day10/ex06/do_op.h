#ifndef DO_OP_H
# define DO_OP_H

int ft_add(char **av);

int ft_sou(char **av);

int ft_mul(char **av);

int ft_div(char **av);

int ft_mod(char **av);

int ft_atoi(char *str);

void ft_putchar(char c);

void ft_putnbr(int nb);

typedef struct s_cal
{
	char *op;
	int (*f)(char **av);
}	t_cal;
#endif

