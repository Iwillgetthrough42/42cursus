#include "../lib.h"

int 	getsize(t_stack *a)
{
	int i;

	i = 0;
	while(a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int 	findmin(t_stack *a)
{
	int min;

	min = a->num;

	while(a)
	{
		if (min > a->num)
			min = a->num;
		a = a->next;
	}
	return (min);
}

int 	getindex(t_stack *a, int min)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->num == min)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}