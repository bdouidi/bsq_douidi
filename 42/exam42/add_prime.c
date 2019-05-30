#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar (char c)
{
	write (1, &c, 1);
}
int ft_atoi( char *str)
{
        int i = 0;
        int stock = 1;
        int num = 0;
        while ( str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == 'n' ||
             str[i] == '\f' || str[i] == '\r')
                i++;
        if ( str[i] == '-')
		return 0;
        while (str[i] && (str[i] >= '0' && str[i] <= '9'))
        {
                num = num * 10 + str[i] - '0';
                i++;
        }
        return ( num * stock);
}

int ft_putnbr(int nb)
{
	if ( nb < 0)
		return 0;
	if ( nb >= 0 && nb < 10)
		ft_putchar('0' + nb);
	else
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
	return 0;
}

int ft_ad(char *str)
{
	int c = ft_atoi(str);
	int i = 0;
	int stock = 1;
	
	if ( c > 63457867)
		return 0;
	while (i <= c)
	{
		while (i % 2 == 0)
			i++;
		if (i % 2 != 0)
			stock = stock + i;
		i++;
	}
	return ft_putnbr(stock);
}

int main (int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		printf("mauvais usage");
		return 0;
	}
	else
		ft_ad(argv[1]);
	write(1, "\n", 1);
	return 0;
}
