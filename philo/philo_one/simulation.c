#include "philo_one.h"

void sleepthink(t_philo *ph)
{
	ft_printing(ph->nb, gettime() - ph->timestart, "is sleeping", ph);
	ft_sleep(ph->info->time_to_sleep);
	ft_printing(ph->nb, gettime() - ph->timestart, "is Thinking", ph);
	//usleep(100);
}

void *check_death(void *tmp)
{
	t_philo *ph;

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
		if (ph->info->died)
			return (NULL);
		pthread_mutex_unlock(&ph->info->death);
	}
}

void checkifenough(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->death);
	ph->info->eaten++;
	if (ph->info->eaten >= ph->info->musteat)
	{
		if (!ph->info->died)
			ft_print("everyone has eaten enough");
		ph->info->died = 1;
		pthread_mutex_unlock(&ph->info->death);
	}
		pthread_mutex_unlock(&ph->info->death);
}

int eat(t_philo *ph)
{
	int left;
	int right;

	left = ph->nb;
	right = (ph->nb + 1) % (ph->info->num_of_philo);
	if (ph->nb % 2 == 1)
	{
		pthread_mutex_lock(&ph->info->forks[right]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
		pthread_mutex_lock(&ph->info->forks[left]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
	}
	else if (ph->nb % 2 == 0)
	{
		pthread_mutex_lock(&ph->info->forks[left]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
		pthread_mutex_lock(&ph->info->forks[right]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork", ph);
	}
	ph->time_last_meal = gettime();
	ft_printing(ph->nb, gettime()-ph->timestart, "is eating", ph);
	ft_sleep(ph->info->time_to_eat);
	if (ph->info->musteat != 0)
		checkifenough(ph);
	pthread_mutex_unlock(&ph->info->forks[right]);
	pthread_mutex_unlock(&ph->info->forks[left]);
	return (1);
}


void 	*simulation(void *ph)
{
	pthread_t control;

	(void)control;
	((t_philo *)ph)->timestart = gettime();
	((t_philo *)ph)->time_last_meal = gettime();
	pthread_create(&control, NULL, &check_death, ph);
	while (((t_philo *)ph)->info->died == 0)
	{
		eat((t_philo *)ph);
		sleepthink((t_philo *)ph);
	}
	pthread_join(control, NULL);
	return (NULL);
}