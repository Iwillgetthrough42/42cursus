#include "../lib.h"

void 	sortk(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;
	int		temp;

	tmp = NULL;
	node = *stack;
	while (node != NULL)
	{
		tmp = node->next;
		while (tmp != NULL)
		{
			if (tmp->num < node->num)
			{
				temp = node->num;
				node->num = tmp->num;
				tmp->num = temp;
			}
			tmp = tmp->next;
		}
		node = node->next;
	}
}

int 	getsize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int 	findmin(t_stack *a)
{
	int	min;

	min = a->num;
	while (a)
	{
		if (min > a->num)
			min = a->num;
		a = a->next;
	}
	return (min);
}

int 	getindex(t_stack *a, int min)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->num == min)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int 	getnum(int index, t_stack *a, int *num)
{
	int	i;

	i = 1;
	while (a)
	{
		if (i == index)
		{
			*num = a->num;
			return (1);
		}
		a = a->next;
		i++;
	}
	return (0);
}
