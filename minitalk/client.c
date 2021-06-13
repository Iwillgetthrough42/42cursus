#include "minitalk.h"

int	sendbitbybit(int pid, char *str)
{
	int	i;
	int	shift;

	i = 0;
	while (str[i] != '\0')
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					return (0);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					return (0);
			}
			usleep(100);
			shift++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	sendbitbybit(pid, argv[2]);
}
