#include "philo_one.h"

int start(t_philo_one *philo)
{
	int 		i;
	pthread_t 	phil[philo->num_of_philo];
	t_philo  	*ph;

	ph = (t_philo *)malloc(sizeof(t_philo) * (philo->num_of_philo + 1));
	pthread_mutex_init(&philo->print, NULL);
	pthread_mutex_init(&philo->death, NULL);
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		ph[i].nb = i;
		ph[i].info = philo;
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_create(&phil[i], NULL, &simulation, &ph[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_join(phil[i], NULL) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_mutex_destroy(&philo->forks[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_philo_one philo;

	if (argc != 5 && argc != 6)
	{
		ft_print("Error argument\n");
		return (0);
	}
	philo.musteat = 0;
	philo.num_of_philo = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	philo.died = 0;
	if (argc == 6)
		philo.musteat = ft_atoi(argv[5]);
	philo.died = 0;
	return (start(&philo));
}