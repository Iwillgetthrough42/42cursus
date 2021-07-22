#include "philo_one.h"

void 	sleeping(int i, int time)
{
	gettimeofday(&tv, NULL);
	ft_printf("%d philosopher %d is sleeping", tv.tv_usec - time, i);
	usleep(info.time_to_sleep);
}

void 	think(int i, int time)
{
	struct 	timeval tv;

	gettimeofday(&tv, NULL);
	ft_printf("%d philosopher %d is thinking\n", tv.tv_usec - time, i);
	usleep(1000);
}

void	*simulation(void *a)
{
	int 	i;
	int 	time;
	struct 	timeval tv;

	i = *(int *)a;

	gettimeofday(&tv, NULL);
	time = tv.tv_usec;
	musteat = 0;
	while (1)
	{
		pickup(i, time);
		//if (!eat(i, time) || eat(i, time) == 2)
			//break ;
		//putdown(i);
		//sleeping(i, time);
		//think(i, time);
	}
	return (NULL);
}

int 	start()
{
	int 			i;
	pthread_t 		philo[info.num_of_philo];
	int 			*a;
	int  			j;

	j = 0;
	forks = malloc(sizeof(pthread_mutex_t) * info.num_of_philo);
	while (j < info.num_of_philo)
	{
		if (pthread_mutex_init(&forks[j], NULL) != 0)
			return (0);
		j++;
	}
	i = 0;
	while (i < info.num_of_philo)
	{
		if (!(a = (int *)malloc(sizeof(int))))
			return (0);
		*a = i;
		if (pthread_create(&philo[i], NULL, &simulation, a)!= 0)
			return (0);
		i++;
	}
	j = 0;
	while (j < info.num_of_philo)
	{
		if (pthread_join(philo[j], NULL) != 0)
			return (0);
		j++;
	}
	j = 0;
	while (j < info.num_of_philo)
	{
		if (pthread_mutex_destroy(&forks[j]) != 0)
			return (0);
		j++;
	}
	return (1);
}

int 	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		write(1, "Error argument\n", 15);
	info.num_of_philo = ft_atoi(argv[1]);
	info.time_to_die = ft_atoi(argv[2]);
	info.time_to_eat = ft_atoi(argv[3]);
	info.time_to_sleep = ft_atoi(argv[4]);
	info.num_musteat = 0;
	if (argc == 6)
		info.num_musteat = ft_atoi(argv[5]);
	if (!start())
		return (0);
	return (1);
}
