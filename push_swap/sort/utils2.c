#include "../lib.h"

int 	getindexk(t_stack *a, int key_nbr)
{
	int i;

	i = 1;
	while (a)
	{
		if (a->num <= key_nbr)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int 	getmax(t_stack *b)
{
	int max;

	max = b->num;
	while (b)
	{
		if (b->num > max)
			max = b->num;
		b = b->next;
	}
	return (max);
}
