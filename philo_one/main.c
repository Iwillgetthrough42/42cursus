#include "philo_one.h"

int	isnumbers(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '-' && \
				 ft_isdigit(argv[i][j + 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	range(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int checkarg(int argc, char **argv)
{
	if (!isnumbers(argc, argv))
		return (0);
	if (!range(argc, argv))
		return (0);
	return (1);
}

void checkenough(t_philo *ph)
{
	int j;
	int l;

	pthread_mutex_lock(&ph->info->death);
	if (ph[0].info->hasmusteat && ph[0].info->num_of_philo != 1)
	{
		l = 1;
		j = 0;
		while (j < ph[0].info->num_of_philo)
		{
			if (ph[j].eaten < ph[0].info->musteat)
			{
				l = 0;
				break ;
			}
			j++;
		}
		if (l == 1)
		{
			pthread_mutex_lock(&ph->info->print);
			ph->info->died = 1;
			pthread_mutex_unlock(&ph->info->death);
		}
	}
	pthread_mutex_unlock(&ph->info->death);
}

int startthreads(pthread_t *phil, t_philo *ph)
{
	int i;

	i = 0;
	while (i < ph[0].info->num_of_philo)
	{
		if (pthread_create(&phil[i], NULL, &simulation, &ph[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < ph[0].info->num_of_philo)
	{
		while (!ph[0].info->died)
			checkenough(ph);
		if (pthread_detach(phil[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < ph[0].info->num_of_philo)
	{
		if (pthread_mutex_destroy(&ph[0].info->forks[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&ph[0].info->print) != 0)
			return (0);
	if (pthread_mutex_destroy(&ph[0].info->death) != 0)
		return (0);
	return (1);
}

int start(t_philo_one *philo)
{
	int 		i;
	pthread_t 	phil[philo->num_of_philo];
	t_philo  	*ph;
	int 		l;

	l = 0;
	ph = (t_philo *)malloc(sizeof(t_philo) * philo->num_of_philo);
	pthread_mutex_init(&philo->print, NULL);
	pthread_mutex_init(&philo->death, NULL);
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
		{
			ft_free(ph, philo);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		ph[i].nb = i + 1;
		ph[i].info = philo;
		i++;
	}
	if (!startthreads(phil, ph))
	{
		ft_free(ph, philo);
		return (0);
	}
	ft_free(ph, philo);
	return (1);
}

int main(int argc, char **argv)
{
	t_philo_one *philo;

	philo = (t_philo_one *)malloc(sizeof(t_philo_one));
	if (argc != 5 && argc != 6)
	{
		free(philo);
		ft_print("Error argument\n");
		return (0);
	}
	if (!checkarg(argc, argv))
	{
		free(philo);
		ft_print("Error argument\n");
		return (0);
	}
	philo->musteat = 0;
	philo->hasmusteat = 0;
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->died = 0;
	if (argc == 6)
	{
		philo->hasmusteat = 1;
		philo->musteat = ft_atoi(argv[5]);
	}
	philo->died = 0;
	philo->count = 0;
	if (!start(philo))
	{
		free(philo);
		return (0);
	}
	return (1);
}