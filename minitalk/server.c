#include "minitalk.h"

static t_msg	g_msgbit;

void	getbitbybit(int bit)
{
	g_msgbit.num += (bit & 1) << g_msgbit.size;
	g_msgbit.size++;
	if (g_msgbit.size == 7)
	{
		write(1, &g_msgbit.num, g_msgbit.size);
		g_msgbit.num = 0;
		g_msgbit.size = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*str;

	pid = getpid();
	str = ft_itoa(pid);
	write(1, str, ft_strlen(str));
	g_msgbit.num = 0;
	g_msgbit.size = 0;
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, getbitbybit);
		signal(SIGUSR1, getbitbybit);
		pause();
	}
	return (1);
}
