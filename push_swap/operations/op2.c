#include "../lib.h"

void	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	revrotate(a);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	revrotate(b);
}
