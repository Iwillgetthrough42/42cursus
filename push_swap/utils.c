#include "lib.h"

int	addback(t_stack **a, t_stack *new)
{
	t_stack	*lst;

	lst = last(*a);
	if (lst)
		lst->next = new;
	else
		*a = new;
	return (1);
}

t_stack	*last(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

void	addfront(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

int 	issorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*node;

	tmp = NULL;
	node = stack;
	while (node != NULL)
	{
		tmp = node->next;
		while (tmp != NULL)
		{
			if (tmp->num < node->num)
				return (0);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}