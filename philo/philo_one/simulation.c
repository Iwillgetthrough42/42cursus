int eat(t_philo *ph)
{
	int left;
	int right;

	left = ph->nb;
	right = (ph->nb + 1) % (ph->info->num_of_philo);
	if (ph->nb % 2 == 1)
	{
		pthread_mutex_lock(ph->info->forks[right]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork");
		pthread_mutex_lock(ph->info->forks[left]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork");
	}
	else if (ph->nb % 2 == 0)
	{
		pthread_mutex_lock(ph->info->forks[left]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork");
		pthread_mutex_lock(ph->info->forks[right]);
		ft_printing(ph->nb, gettime()-ph->timestart, "has taken a fork");
	}
	
}


void 	*simulation(void *ph)
{
	int time_last_meal;

	(t_philo *)ph->timestart = gettime();
	time_last_meal = gettime();
	while (1)
	{
		eat((t_philo *)ph);
	}
}