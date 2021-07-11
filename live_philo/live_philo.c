#include "philo.h"

int check_die_philo(t_philo *philo)
{
	if (philo->time_to_last_eat > philo->time_to_die)
	{
	 	pthread_mutex_lock(philo->mutex_philo_said);
	 	printf("Philo %d died\n", philo->numer_philo); //died
	 	pthread_mutex_unlock(philo->mutex_philo_said);
		*(philo->key_die_philo) = 1;
	 	return (-1);
	}
	return (0);
}

void *mode_of_life_philo(void *philo_one)
{
	t_philo *philo;

	philo = (t_philo *)philo_one;
	while (philo->key_die_philo == 0)
	{
	 	pthread_mutex_lock(&philo->left_hand->mutex_fork);
	 	pthread_mutex_lock(philo->mutex_philo_said);
		printf("Philo %d take fork %d\n", philo->numer_philo, philo->left_hand->numer_fork);
	 	pthread_mutex_unlock(philo->mutex_philo_said);
	 	pthread_mutex_lock(&philo->right_hand->mutex_fork);
	 	pthread_mutex_lock(philo->mutex_philo_said);
	 	printf("Philo %d take fork %d\n", philo->numer_philo, philo->right_hand->numer_fork);
	 	printf("Philo %d eating\n", philo->numer_philo);
	 	usleep(philo->time_to_eat * 1000);
		philo->time_to_last_eat = time->tv_usec;
	 	pthread_mutex_unlock(philo->mutex_philo_said);
	 	pthread_mutex_unlock(&philo->right_hand->mutex_fork);
	 	pthread_mutex_unlock(&philo->left_hand->mutex_fork);
	 	if (philo->count_eat != -1)
	 	{
	 		philo->count_eat--;
	 		if (philo->count_eat == 0)
	 			break ;
	 	}
	 	pthread_mutex_lock(philo->mutex_philo_said);
	 	printf("Philo %d sleaping\n", philo->numer_philo);	//sleaping
	 	pthread_mutex_unlock(philo->mutex_philo_said);
		usleep(philo->time_to_sleap * 1000);
		pthread_mutex_lock(philo->mutex_philo_said);
		printf("Philo %d thinkeng\n", philo->numer_philo);
		pthread_mutex_unlock(philo->mutex_philo_said);
		usleep(1000);
	// 	if (philo->time_to_last_eat > philo->time_to_die)
	// 	{
	// 		pthread_mutex_lock(philo->mutex_philo_said);
	// 		printf("Philo %d died\n", philo->numer_philo); //died
	// 		pthread_mutex_unlock(philo->mutex_philo_said);
	//		*(philo->key_die_philo) = 1;
	// 		return (NULL);
	// 	}
	}
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
		usleep(1000);
	}
	philo_tmp = all->philos;
	while (philo_tmp)
	{
		if (philo_tmp->numer_philo % 2 == 0)
			pthread_create(&philo_tmp->flow_philo, NULL, mode_of_life_philo, (void *)philo_tmp);
		philo_tmp = philo_tmp->next;
		usleep(1000);
	}
	philo_tmp = all->philos;
	while(philo_tmp)
	{
		pthread_join(philo_tmp->flow_philo, NULL);
		philo_tmp = philo_tmp->next;
	}
	usleep(10000);
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
	//death_philo(all);
	//free_forks(all);
	return (0);
}
