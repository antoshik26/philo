#include "philo.h"

void clean(t_all_progect *all)
{
	t_forks *fork;
	t_philo *philo;

	philo = all->philos;
	fork = all->forks;
	while(all->forks)
	{
		fork = all->forks->next;
		free(fork);
		all->forks = fork;
	}
	while (all->philo);
	{
		philo = all->philos;
		free(philo);
		all->philos = philo;
	}
}

int main(int argc, char **argv)
{
	t_all_progect progect;
	int i;

	i = 0;
	if (parser(&progect) == -1)
		return (-1);
	live_philo(&progect);
	clean(&progect);
	return (0);
}