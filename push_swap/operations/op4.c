#include "../lib.h"

void	swap(t_stack *a)
{
	int tmp;

	if (a && a->next)
	{
		tmp = a->num;
		a->num = a->next->num;
		a->next->num = tmp;
	}
}

void	push(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	t_stack *new;
	
	if (*a && !(*b))
	{
		tmp = *a;
		*b = (t_stack *)malloc(sizeof(t_stack));
		(*b)->num = (*a)->num;
		(*b)->next = NULL;
		(*a) = (*a)->next;
		free(tmp);
	}
	else
	{
		if (*a)
		{
			tmp = *a;
			new = (t_stack *)malloc(sizeof(t_stack));
			new->num = (*a)->num;
			new->next = NULL;
			addfront(b, new);
			*a = (*a)->next;
			free(tmp);
		}
	}
}

void	rotate(t_stack **a)
{
	t_stack *tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		addback(a, tmp);
	}
}

void	revrotate(t_stack **a)
{
	t_stack *tmp1;
	t_stack	*tmp2;
	
	tmp1 = *a;
	while ((*a)->next)
	{
		if ((*a)->next->next == NULL)
			tmp2 = *a;
		*a = (*a)->next;
	}
	(*a)->next = tmp1;
	tmp1 = *a;
	tmp2->next = NULL;
}

