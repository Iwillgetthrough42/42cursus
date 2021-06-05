#include "../lib.h"

void	sa(t_stack *a)
{
	int tmp;

	if (a && a->next)
	{
		tmp = a->num;
		a->num = a->next->num;
		a->next->num = tmp;
	}
}

void	sb(t_stack *b)
{
	sa(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *new;

	if (*a && !(*b))
	{
		*b = (t_stack *)malloc(sizeof(t_stack));
		(*b)->num = (*a)->num;
		(*b)->next = NULL;
		(*a) = (*a)->next;
	}
	else
	{
		if (*a)
		{
			new = (t_stack *)malloc(sizeof(t_stack));
			new->num = (*a)->num;
			new->next = NULL;
			addfront(b, new);
			*a = (*a)->next;
		}
	}
}

void	pa(t_stack **a, t_stack **b)
{
	pb(b, a);
}
