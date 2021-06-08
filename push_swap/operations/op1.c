#include "../lib.h"

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}

void	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	push(a, b);
}

void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	push(b, a);
}
