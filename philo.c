#include "philo.h"
t_all_progect g_progect;

void allocate(t_all_progect *all)
{
	all->philos = NULL;
	all->forks = NULL;
	pthread_mutex_init(&all->mutex_philo_said, NULL);
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

	allocate(&g_progect);
	if (parser(&g_progect, argc, argv) == -1)
		return (-1);
	live_philo(&g_progect);
	//clean(&progect);
	return (0);
}