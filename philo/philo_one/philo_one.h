#ifndef PHILO_ONE_H
#define PHILO_ONE_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>


typedef struct 	s_philo_one
{
	int  			num_of_philo;
	int  			time_to_die;
	int  			time_to_eat;
	int  			time_to_sleep;
	int  			musteat;
	int  			hasmusteat;
	int  			died;
	int  			eaten;
	int  			nb;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
}				t_philo_one;

typedef struct 	s_philo
{
	int 		nb;
	t_philo_one *info;
	long  		timestart;
	long  		time_last_meal;
}				t_philo;

int				ft_atoi(const char *str);
void 			ft_putchar(char c);
void 			ft_putnbr(int nb);
void 			ft_print(char *str);
int 			ft_strlen(char *str);
int 			gettime();
void 			ft_printing(int i, int tim, char *str, t_philo *ph);
void 			*simulation(void *ph);
void  			ft_sleep(long mili);
int				ft_isdigit(int c);


#endif