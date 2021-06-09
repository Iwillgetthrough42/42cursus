#include "../lib.h"

void	frombtoa(t_stack **a, t_stack **b)
{
	int	max;
	int	middle;
	int	len;

	len = getsize(*b);
	while (*b)
	{
		max = getmax(*b);
		while ((*b)->num != max)
		{
			middle = len / 2 + len % 2;
			if (max == (*b)->next->num)
				sb(*b);
			else if (middle > getindex(*b, max))
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
		len--;
	}
}
