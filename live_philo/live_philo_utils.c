#include "philo.h"

int	free_forks(t_all_progect *all)
{
	t_forks	*fork;

	fork = all->forks;
	while (fork)
	{
		if (pthread_mutex_destroy(&fork->mutex_fork) == -1)
			return (-1);
		fork = fork->next;
	}
	return (0);
}

int	init_mutex_forks(t_all_progect *all)
{
	t_forks	*fork;

	fork = all->forks;
	while (fork)
	{
		if (pthread_mutex_init(&fork->mutex_fork, NULL))
			return (-1);
		fork = fork->next;
	}
	return (0);
}

int	death_philo(t_all_progect *all)
{
	t_philo	*philo;

	philo = all->philos;
	while (philo)
	{
		if (pthread_detach(philo->flow_philo) == -1)
			return (-1);
		philo = philo->next;
	}
	return (0);
}

int	check_die_philo(t_philo *philo)
{
	if ((gettime() - philo->time_to_last_eat) > \
			(unsigned long long)philo->time_to_die)
	{
		printf("%llu: Philo %d died\n", gettime_to_print(philo->time_start), \
			philo->numer_philo);
		*(philo->key_die_philo) = 1;
		return (-1);
	}
	return (0);
}
