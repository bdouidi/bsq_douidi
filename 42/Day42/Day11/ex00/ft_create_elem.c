#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>


t_list *ft_create_elem(void *data)
{
  t_list *tmp;
  
  tmp = NULL;
  tmp = malloc(sizeof(t_list));
  if (tmp)
  {
	  tmp->data = data;
	  tmp->next = NULL;
  }
  return tmp;
}
int main()
{
	void *data;
	char *a = "x";

	data = &a;
	t_list *list = ft_create_elem(data);
	while (list)
	{
		puts(list->data);
		printf("\n");
		list = list->next;
	}
	return 0;
}
