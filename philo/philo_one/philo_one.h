#ifndef PHILO_ONE_H
#define PHILO_ONE_H

typedef struct 	s_philo_one
{
	int  			num_of_philo;
	int  			time_to_die;
	int  			time_to_eat;
	int  			time_to_sleep;
	int  			musteat;
	int  			died;
	int  			nb;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_philo_one;

typedef struct 	s_philo
{
	int 		nb;
	t_philo_one *info;
	long  		timestart;
}				t_philo;

int				ft_atoi(const char *str);
void 			ft_putchar(char c);
void 			ft_putnbr(int nb);
void 			ft_print(char *str);
void 			ft_printing(int i, int tim, char *str);
int 			ft_strlen(char *str);


#endif