#include "philo_one.h"

int start(t_pjilo_one *philo)
{
	int 		i;
	pthread_t 	philo[philo->num_of_philo];
	t_philo  	ph;

	ph = (t_philo *)malloc(sizeof(t_philo) * (philo->num_of_philo + 1));
	pthread_mutex_init(&philo->print, NULL);
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t * philo->num_of_philo));
	i = 0;
	while (i < philo->num_of_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		ph.nb = i;
		ph.info = philo;
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		pthread_create(&philo[i], NULL, &simulation, &ph[i]);
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		pthread_mutex_destroy(&philo->forks[i], NULL);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_philo_one philo;

	if (argc != 5 && argc != 6)
	{
		ft_printf("Error argument\n");
		return (0);
	}
	philo.musteat;
	philo.num_of_philo = ft_atoi(argv[1]);
	philo.time_to_die = ft_atoi(argv[2]);
	philo.time_to_eat = ft_atoi(argv[3]);
	philo.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo.musteat = ft_atoi(argv[5]);
	philo.died = 0;
	start(&philo);
}