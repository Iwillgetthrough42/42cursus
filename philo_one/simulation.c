#include "philo_one.h"

void sleepthink(t_philo *ph)
{
	if (ph->info->died == 0)
	{
		ft_printing(ph->nb, gettime() - ph->timestart, "is sleeping", ph);
		ft_sleep(ph->info->time_to_sleep);
	}
	if (ph->info->died == 0)
		ft_printing(ph->nb, gettime() - ph->timestart, "is Thinking", ph);
}

void *check_death(void *tmp)
{
	t_philo *ph;
	int  	l;

	l = 1;
	ph = (t_philo *)tmp;
	while (1)
	{
		pthread_mutex_lock(&ph->info->death);
		if (gettime() - ph->time_last_meal > ph->info->time_to_die)
		{
			if (!ph->info->died)
				ft_printing(ph->nb, gettime() - ph->timestart, "died", ph);
			ph->info->died = 1;
			pthread_mutex_unlock(&ph->info->death);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->info->death);
		if (ph->info->died)
			return (NULL);	
	}
}

int eat(t_philo *ph)
{
	int left;
	int right;

	left = ph->nb - 1;
	right = ((ph->nb) % (ph->info->num_of_philo));	
	if (ph->nb % 2 == 1)
	{
		pthread_mutex_lock(&ph->info->forks[left]);
		if (!ph->info->died)
			ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
		pthread_mutex_lock(&ph->info->forks[right]);
		if (!ph->info->died)
			ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
	}
	else if (ph->nb % 2 == 0)
	{
		pthread_mutex_lock(&ph->info->forks[right]);
		if (!ph->info->died)
			ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
		pthread_mutex_lock(&ph->info->forks[left]);
		if (!ph->info->died)
			ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
	}
	ph->time_last_meal = gettime();
	if (!ph->info->died)
		ft_printing(ph->nb, gettime()-ph->timestart, "is eating", ph);
	if (!ph->info->died)
		ft_sleep(ph->info->time_to_eat);
	if (ph->info->hasmusteat != 0 && !ph->info->died)
		ph->eaten++;
	pthread_mutex_unlock(&ph->info->forks[right]);
	pthread_mutex_unlock(&ph->info->forks[left]);
	return (1);
}


void 	*simulation(void *ph)
{
	pthread_t control;

	((t_philo *)ph)->eaten = 0;
	((t_philo *)ph)->timestart = gettime();
	((t_philo *)ph)->time_last_meal = gettime();
	pthread_create(&control, NULL, &check_death, ph);
	while (1)
	{
		if (eat((t_philo *)ph))
			sleepthink((t_philo *)ph);
		if (((t_philo *)ph)->info->died == 1)
		{
			pthread_detach(control);
			return (NULL);
		}
	}
}