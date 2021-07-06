#include "philo.h"

void *mode_of_life_philo(void *philo_one)
{
	// t_philo *philo;

	void *a;
	a = philo_one;
	// progect = (t_all_progect *)all;
	// while (philo->time_to_last_eat < time_to_die || philo->count_eat)
	// {

	// 	philo->count_eat--;
	// }
	return (NULL);
}

//int mode_of_life_philo(void *philo_one)
//{
//	return (NULL);
//}


int birth_philo(t_all_progect *all)
{
	int i;
	t_philo *philo_tmp;

	i = 0;
	philo_tmp = all->philos;
	while (philo_tmp)
	{
		if (philo_tmp->numer_philo % 2 == 1)
			pthread_create(&philo_tmp->flow_philo, NULL, mode_of_life_philo, (void *)philo_tmp);
		philo_tmp = philo_tmp->next;
	}
	philo_tmp = all->philos;
	while (philo_tmp)
	{
		if (philo_tmp->numer_philo % 2 == 0)
			pthread_create(&philo_tmp->flow_philo, NULL, mode_of_life_philo, (void *)all);
		philo_tmp = philo_tmp->next;
	}
	philo_tmp = all->philos;
	while(philo_tmp)
	{
		pthread_join(philo_tmp->flow_philo, NULL);
		philo_tmp = philo_tmp->next;
	}
	return (0);
}

int death_philo(t_all_progect *all)
{
	t_philo *philo;

	philo = all->philos;
	while (philo)
	{
		if (pthread_detach(philo->flow_philo) == -1)
			return (-1);
		philo = philo->next;
	}
	return (0);
}

int free_forks(t_all_progect *all)
{
	t_forks *fork;

	fork = all->forks;
	while(fork)
	{
		if (pthread_mutex_destroy(&fork->mutex_fork) == -1)
			return (-1);
		fork = fork->next;
	}
	return (0);
}

int init_mutex_forks(t_all_progect *all)
{
	t_forks *fork;

	fork = all->forks;
	while(fork)
	{
		if (pthread_mutex_init(&fork->mutex_fork, NULL))
			return (-1);
		fork = fork->next;
	}
	return (0);
}

int live_philo(t_all_progect *all)
{
	init_mutex_forks(all);
	birth_philo(all);
	death_philo(all);
	free_forks(all);
	return (0);
}
