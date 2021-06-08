#include "../lib.h"

void 	freestack(t_stack **stack)
{
	t_stack *tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = tmp;
		}
		free(*stack);
		*stack = NULL;
	}
}