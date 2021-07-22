#ifndef PHILO_ONE_H
#define PHILO_ONE_H

#include "../libft/libft.h"
#include "../ft_printf/lib.h"
#include "pthread.h"
#include <sys/time.h>

typedef struct 	s_info
{
	int num_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_musteat;

}				t_info;

t_info 			info;
pthread_mutex_t	*forks;
struct 			timeval tv;
int 			lasteat;
int 			musteat;
int 			eat(int i, int time);
void 			putdown(int i);
void 			pickup(int i, int time);



#endif