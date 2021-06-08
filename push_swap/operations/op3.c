#include "../lib.h"

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);	
	revrotate(a);
	revrotate(b);
}