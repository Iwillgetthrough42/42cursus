#include "philo_one.h"

static	int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ');
}

int				ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if (i > 19 || num > 9223372036854775807)
		return ((sign == 1) ? -1 : 0);
	return (sign * num);
}

void 		ft_putchar(char c)
{
	write(1,&c,1);
}

void 		ft_putnbr(int nb)
{
	if(nb == -2147483648)
	{
		ft_putnbr(nb/10);
		ft_putchar('8');
	}
	else if(nb<0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}	 
	else if(nb>9)
	{
		ft_putnbr(nb/10);
		ft_putchar('0'+nb%10);
	}
	else
	{
		ft_putchar('0'+nb);
	}
}

void 		ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

void 		ft_printing(int i, int tim, char *str, t_philo *ph)
{
	pthread_mutex_lock(&ph->info->print);
	ft_putnbr(tim);
	ft_putchar(' ');
	ft_putnbr(i);
	ft_putchar(' ');
	ft_print(str);
	ft_putchar('\n');
	pthread_mutex_unlock(&ph->info->print);
}

int 		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int 		gettime()
{
	struct 	timeval 	curr_time;
	int  	time;

	if (gettimeofday(&curr_time, NULL) == -1)
	{
		ft_print("Error gettime");
		return (0);
	}
	time = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (time);
}

