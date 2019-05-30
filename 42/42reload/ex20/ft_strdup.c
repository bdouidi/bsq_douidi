#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;

	if (!(dest = (char *)malloc(sizeof(char) * strlen(src))))
		return 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return dest;
}
