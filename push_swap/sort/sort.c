#include "../lib.h"

void 	sort3(t_stack **a)
{
	int	min;

	min = findmin(*a);
	if ((*a)->num < (*a)->next->num && (*a)->next->next->num == min)
		rra(a);
	else if ((*a)->num > (*a)->next->num && (*a)->next->next->num == min)
	{
		sa(*a);
		rra(a);
	}
	else if ((*a)->num == min && (*a)->next->num > (*a)->next->next->num)
	{
		sa(*a);
		ra(a);
	}
	else if ((*a)->next->num == min)
	{
		if ((*a)->num < (*a)->next->next->num)
			sa(*a);
		else
			ra(a);
	}
}

void	pushback(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
	}
}

void	sortto10(t_stack **a, t_stack **b)
{
	int	min;
	int	middle;
	int	len;

	len = getsize(*a);
	while (len > 3)
	{
		min = findmin(*a);
		middle = len / 2 + len % 2;
		while ((*a)->num != min)
		{
			if (min == (*a)->next->num)
				sa(*a);
			else if (middle >= getindex(*a, min))
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
		len = getsize(*a);
	}
	sort3(a);
}

void 	sort1to10(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
	{
		if (*a > (*a)->next)
			sa(*a);
	}
	else if (len == 3)
		sort3(a);
	else
		sortto10(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = getsize(*a);
	if (len <= 10)
	{
		sort1to10(a, b, len);
		pushback(a, b);
	}
	else if (len > 10 && len <= 100)
	{
		sort10to100(a, b, len, 4);
		sort1to10(a, b, getsize(*a));
		frombtoa(a, b);
	}
	else if (len > 100)
	{
		sort10to100(a, b, len, 8);
		sort1to10(a, b, getsize(*a));
		frombtoa(a, b);
	}
}
