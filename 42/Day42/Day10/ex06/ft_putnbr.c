#include "do_op.h"
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar('0' + nb);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb = nb * -1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
