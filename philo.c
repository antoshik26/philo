#include "philo.h"

void allocate(t_all_progect *all)
{
	all->philos = NULL;
	all->forks = NULL;
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
	t_all_progect progect;

	allocate(&progect);
	if (parser(&progect, argc, argv) == -1)
		return (-1);
	live_philo(&progect);
	clean(&progect);
	return (0);
}