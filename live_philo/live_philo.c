#include "philo.h"

int	check_philo(t_all_progect *all)
{
	t_philo	*philo_tmp;

	while (1)
	{
		philo_tmp = all->philos;
		check_die_philo(philo_tmp);
		if (all->key_die_philo == 1 || all->eat_your_fill == 1)
		{
			death_philo(all);
			return (0);
		}
		all->eat_your_fill = 1;
		while (philo_tmp)
		{
			if (all->eat_your_fill == 1 && philo_tmp->count_eat == 0)
				all->eat_your_fill = 1;
			else
			{
				all->eat_your_fill = 0;
				break ;
			}
			philo_tmp = philo_tmp->next;
		}
	}
	return (0);
}

int	eating_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_hand->mutex_fork);
	printf("%llu: Philo %d take fork %d\n", \
		gettime_to_print(philo->time_start), philo->numer_philo, \
		philo->left_hand->numer_fork);
	pthread_mutex_lock(&philo->right_hand->mutex_fork);
	printf("%llu: Philo %d take fork %d\n", \
		gettime_to_print(philo->time_start), philo->numer_philo, \
		philo->right_hand->numer_fork);
	printf("%llu: Philo %d eating\n", \
		gettime_to_print(philo->time_start), philo->numer_philo);
	philo->time_to_last_eat = gettime();
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->right_hand->mutex_fork);
	pthread_mutex_unlock(&philo->left_hand->mutex_fork);
	return (0);
}

void	*mode_of_life_philo(void *philo_one)
{
	t_philo	*philo;

	philo = (t_philo *)philo_one;
	while (1)
	{
		eating_philo(philo);
		if (philo->count_eat != -1)
		{
			philo->count_eat--;
			if (philo->count_eat == 0)
				break ;
		}
		printf("%llu: Philo %d sleaping\n", \
			gettime_to_print(philo->time_start), philo->numer_philo);
		usleep(philo->time_to_sleap * 1000);
		printf("%llu: Philo %d thinkeng\n", \
			gettime_to_print(philo->time_start), philo->numer_philo);
	}
	return (NULL);
}

int	birth_philo(t_all_progect *all)
{
	int		i;
	t_philo	*philo_tmp;

	i = 0;
	philo_tmp = all->philos;
	while (philo_tmp)
	{
		if (philo_tmp->numer_philo % 2 == 1)
			pthread_create(&philo_tmp->flow_philo, NULL, \
				mode_of_life_philo, (void *)philo_tmp);
		philo_tmp = philo_tmp->next;
		usleep(1000);
	}
	philo_tmp = all->philos;
	while (philo_tmp)
	{
		if (philo_tmp->numer_philo % 2 == 0)
			pthread_create(&philo_tmp->flow_philo, NULL, \
				mode_of_life_philo, (void *)philo_tmp);
		philo_tmp = philo_tmp->next;
		usleep(1000);
	}
	check_philo(all);
	return (0);
}

int	live_philo(t_all_progect *all)
{
	init_mutex_forks(all);
	birth_philo(all);
	free_forks(all);
	return (0);
}
