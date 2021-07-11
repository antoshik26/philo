#include "philo.h"
t_all_progect g_progect;

int allocate(t_all_progect *all)
{
	int key;

	key = 0;
	all->philos = NULL;
	all->forks = NULL;
	all->key_die_philo = 0;
	key = gettimeofday(&all->time, &all->time_zone);
	if (key == -1)
		return (-1);
	pthread_mutex_init(&all->mutex_philo_said, NULL);
	return(0);
}

void clean(t_all_progect *all)
{
	t_forks *fork;
	t_forks *fork_tmp;
	t_philo *philo;
	t_philo *philo_tmp;

	philo = all->philos;
	fork = all->forks;
	while(fork)
	{
		pthread_mutex_destroy(&fork->mutex_fork);
		fork_tmp = fork->next;
		free(fork);
		fork = fork_tmp;
	}
	while (philo)
	{
		philo_tmp = philo->next;
		free(philo);
		philo = philo_tmp;
	}
}

int main(int argc, char **argv)
{
	t_all_progect g_progect;

	if (allocate(&g_progect))
		return (-1);
	if (parser(&g_progect, argc, argv) == -1)
		return (-1);
	live_philo(&g_progect);
	//clean(&progect);
	return (0);
}