#include "../lib.h"

t_stack 	*duplist(t_stack *a)
{
	t_stack *new;
	t_stack *tmp;
	t_stack *tmp2;

	tmp = a;
	tmp2 = NULL;
	while (a)
	{
		if (!(new = (t_stack *)(malloc(sizeof(t_stack)))))
			return (0);
		new->num = a->num;
		new->next = NULL;
		addback(&tmp2, new);
		a = a->next;
	}
	a = tmp;
	return (tmp2);
}

int 	checkunderkeynbr(t_stack *a, int key_nbr)
{
	while (a)
	{
		if (a->num <= key_nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void 	stackop(t_stack **a, int middle, int key_nbr)
{
	int index;

	index = getindexk(*a, key_nbr);
	if (getindex(*a, (*a)->next->num) == index)
		sa(*a);
	else if (index > middle)
		rra(a);
	else
		ra(a);
}

void	sort10to100(t_stack **a, t_stack **b, int len, int num)
{
	int 	key_nbr;
	t_stack *k;
	int 	middle;
	int 	length;

	k = NULL;
	length = len;
	while (length > len / num)
	{
		middle = length / 2 + length % 2;
		k = duplist(*a);
		sortk(&k);
		getnum(length / num, k, &key_nbr);
		while (checkunderkeynbr(*a, key_nbr))
		{
			if ((*a)->num <= key_nbr)
			{
				pb(a, b);
				length--;
			}
			else
				stackop(a, middle, key_nbr);
		}
		freestack(&k);
	}
}