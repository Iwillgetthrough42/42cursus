#include "lib.h"

int	initstack(t_stack **a, char **argv, int argc)
{
	int		i;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		new = (t_stack *)(malloc(sizeof(t_stack)));
		if (!new)
			return (0);
		new->num = ft_atoi(argv[i]);
		new->next = NULL;
		addback(a, new);
		i++;
	}
	return (1);
}

int	dublicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	range(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	isnumbers(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '-' && \
				 ft_isdigit(argv[i][j + 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (dublicates(argc, argv) == 0 || \
		range(argc, argv) == 0 || \
		isnumbers(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		freestack(&a);
		freestack(&b);
		return (0);
	}
	initstack(&a, argv, argc);
	sort(&a, &b);
	freestack(&a);
	freestack(&b);
	return (1);
}
