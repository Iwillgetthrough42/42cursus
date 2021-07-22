#include "philo_one.h"

int 	eat(int i, int time)
{
	gettimeofday(&tv, NULL);
	lasteat = tv.tv_usec - time;
	if (lasteat > info.time_to_die)
	{
		ft_printf("%d philosopher %d died", tv.tv_usec - time, i);
		return (0);
	}
	ft_printf("%d philosopher %d is eating", tv.tv_usec - time, i);
	musteat++;
	if (info.num_musteat)
		if (musteat >= info.num_musteat)
		{
			ft_printf("everyone has eaten enough");
			return (2);
		}
	usleep(info.time_to_eat);
	return (1);
}

void 	putdown(int i)
{
	int right;
	int left;

	right = (i + 1) % info.num_of_philo;
	left = ((i + info.num_of_philo) % info.num_of_philo);
	pthread_mutex_unlock(&forks[right]);
	pthread_mutex_unlock(&forks[left]);
}

void 	pickup(int i, int time)
{
	int right;
	int left;

	gettimeofday(&tv, NULL);
	right = ((i == info.num_of_philo)? 0 : i + 1);
	left = ((i == 0) ? info.num_of_philo : i - 1);
	if (i % 2)
	{
		pthread_mutex_lock(&forks[right]);
		ft_printf("%d philosopher %d has taken a fork", tv.tv_usec - time, i);
		pthread_mutex_lock(&forks[left]);
		ft_printf("%d philosopher %d has taken a fork", tv.tv_usec - time, i);
	}
	else
	{
		pthread_mutex_lock(&forks[left]);
		ft_printf("%d philosopher %d has taken a fork", tv.tv_usec - time, i);
		pthread_mutex_lock(&forks[right]);
		ft_printf("%d philosopher %d has taken a fork", tv.tv_usec - time, i);

	}
}