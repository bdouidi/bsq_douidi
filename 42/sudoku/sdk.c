#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int ft_pars_str_n_line(int argc, char **argv) // on check les lignes 
{
	int i = 1;
	int j = 0;
	int k = 1;
	while ( i < argc)
	{
		if (strlen(argv[i]) != 9)
		{
			printf("error len\n");
			return 0;
		}
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '1' && argv[i][j] <= '9') || argv[i][j] == '.'))
			{
				printf("error char\n");
				return 0;
			}
			j++;
		}
		//printf ("ici pars \n");
		j = 0;
        	while (argv[i][j]) 
        	{ 
                	while (k < j) 
                	{	 
                        	if (argv[i][k] == argv[i][j] && argv[i][j] != '.') 
				{
					printf("error line\n");
                                	return 0;
				}
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

int pars_col_tab (int **tab) // on check les col
{
	int i = 0;
	int j = 0;
	int k = 1;
	int o = 0;

	while (i != 9)
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
			if ( o == 9)
			{
				o = 0;
				i++;
				j++;
			}
                	k = 0; 
		}
	return 1;
}

int pars_block_tab (int **tab)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 2;
	int o = 2;
	int p = 2;
	int q = 1;
	int r = 0;
	int s = 0;
	int t[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	while (i < 9)
	{
		while (k <= m && j <= o)
		{
			t[l] = tab[k][j];
			//printf("%c", t[l]);
			j++;
			l++;
			if (j > p)
			{	
				k++;
				j = 0;
				if ( o == 5)
					j = j + 3;
				if ( o == 8)
					j = j + 6;
			}
		}
		//printf("\n");
		if ( o >= 8)
		{
			m = m +3;
			k = m - 2;
			j = 0;
			o = 2;
			p = 2;
			l = 0;
		}
		else
		{
			k = k - 3;
			o = o + 3;
			p = p + 3;
			j = o - 2;
			l = 0;
		}

		while (t[s])
        	{ 
                	while (q < r) 
                	{	 
                        	if (t[q] == t[r] && t[q] != '.')
				{
					printf("error block\n");	
                                	return 0; 
				}
                        	else 
                                	q++; 
                	} 
			//printf("s = %d, q = %d\n", s, q);
                	r++; 
			s++;
                	q = 0; 
        	}
		s = 0;
		q = 1;
		r = 0;
	       	i++;
		//printf("i = %d\n", i);
	}
	return 1;
}
				


int ft_valid_tab_entre_stand (int argc, char **argv, int **tab) //on rempli check l'ensemble des param si ils sont valident dans le tableau (ligne, col, block) 
{
	int i = 0;
	int k = 0;
	int l = 0;
	int m = 1;
	if (ft_pars_str_n_line(argc, argv) == 1) 
	{
		while (i != 9)
		{	
			while (argv[m][l] != '\0')
			{
				tab[k][l] = argv[m][l];
				l++;
			}
			i++;
			l = 0;
			k++;
			m++;
		}
		if (pars_col_tab (tab) != 1)
			return 0;
		//pars_block_tab(tab);
		if (pars_block_tab (tab) != 1)
			return 0;
	}
	else
	{
		printf("error pars\n");
		return 0;
	}
	return **tab;
}

void display_tab(int **tab)
{
	int i = 0;
	int j = 0;

	while (i != 9)
	{
		while(tab[i][j])
		{
			printf("%c", tab[i][j]);
			if (j != 8)
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}
int main (int argc, char **argv)
{
	int **tab;
	int i = 0;
	if(!(tab = malloc(sizeof(*tab)*9)))
		return 0;
	while ( i < 9)
	{
		tab[i] = malloc(sizeof(**tab) * 9);
		i++;
	}

	if (argc != 10)
		return 0;
	else
	{
		if(ft_valid_tab_entre_stand (argc, argv, tab))
			display_tab(tab);
	}
	return 0;
}
