#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int ft_pars_str(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	int k = 1;
	while ( i < argc)
	{
		if (strlen(argv[i]) != 9)
			return 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '1' && argv[i][j] <= '9' || argv[i][j] == '.'))
				return 0;
			j++;
		}
		//printf ("ici pars \n");
		j = 0;
        	while (argv[i][j]) 
        	{ 
                	while (k < j) 
                	{	 
                        	if (argv[i][k] == argv[i][j] && argv[i][j] != '.') 
                                	return 0; 
                        	else 
                                	k++; 
                	} 
                	j++; 
                	k = 0; 
        	}
		i++;
		j = 0;
	}
	return 1;
}

void display_tab(int tab[9][9])
{
	int m = 0;
	int l = 0;
	while (l < 9)
	{
		while(m < 9)
		{
			printf("%c", tab[l][m]);
			if (m < 8)
				printf(" ");
			m++;
		}
		printf("\n");
		m = 0;
		l++;
	}
}
char ft_pars_n_valid_tab (int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 1;
	int o = 0;
	int tab[9][9];

	if (ft_pars_str(argc, argv) == 1)
	{
		while (tab[i][j] != tab[9][9])
		{		
			while (argv[m][l] != '\0')
			{
				tab[k][l] = argv[m][l];
				l++;
			}
			l = 0;
			k++;
			m++;
			i++;
			j++;
		}
		i = 0;
		j = 0;
		k = 1;

		while (tab[i][j] != tab[9][9])
		{
			while (k < o)
			{	 
                        	if (tab[k][j] == tab[o][j] && tab[o][j] != '.')
				{
					printf("error col\n");
                                	return 0;
				}
                        	else 
                                	k++; 
                	} 
			o++;
			if ( o == 10)
			{
				o = 0;
				i++;
				j++;
			}
                	k = 0; 
		}
		display_tab(tab);
	}
	else
	{
		printf("error pars\n");
		return 0;
	}
	return 0;
}

int main (int argc, char **argv)
{
	if (argc != 10)
	{
		printf("error main\n");
		return 0;
	}
	else
	{
		ft_pars_n_valid_tab(argc, argv);
	}
	return 0;
}
