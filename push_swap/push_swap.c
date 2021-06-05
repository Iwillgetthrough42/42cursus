#include "lib.h"
#include <stdio.h>

int		initstack(t_stack **a, char **argv, int argc)
{
	int 		i;
	t_stack 	*new;

	i = 1;
	while (i < argc)
	{
		if (!(new = (t_stack *)(malloc(sizeof(t_stack)))))
			return (0);
		new->num = ft_atoi(argv[i]);
		new->next = NULL;
		addback(a, new);
		i++;
	}
	return(1);
}

int 	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc == 1)
		return (0);
	initstack(&a, argv, argc);
	sort(&a, &b);
	t_stack *tmp = a;
	while(a)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
	tmp = b;
	while(b)
	{
		printf("%d\n", b->num);
		b = b->next;
	}
	return (1);
}