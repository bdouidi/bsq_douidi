#include <stdio.h>
#include <stdlib.h>
int ft_atoi( char *str)
{
	int i = 0;
	int stock = 1;
	int num = 0;
	while ( str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == 'n' ||
	     str[i] == '\f' || str[i] == '\r')
		i++;
	if ( str[i] == '-')
		stock = - 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return ( num * stock);
}
