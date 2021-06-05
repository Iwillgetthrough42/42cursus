#include "../lib.h"

void	ra(t_stack **a)
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

void	rb(t_stack **b)
{
	ra(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
}

void	rra(t_stack **a)
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

void	rrb(t_stack **b)
{
	rra(b);
}
