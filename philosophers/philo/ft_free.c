#include "philo_one.h"

void ft_free(t_philo *ph, t_philo_one *philo)
{
	free(philo->forks);
	free(ph);
}