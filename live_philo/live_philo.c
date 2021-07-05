#include "philo.h"

int mode_of_life_philo(void *all)
{
	t_all_progect *ptogect;

	progect = (t_all_progect *)all;
	return (NULL);
}

int birth_philo(t_all_progect *all)
{
	int i;
	t_philo *philo_tmp;

	i = 0;
	philo_tmp = philo;
	while (philo_tmp)
	{
		if (numer_philo % 2 == 1)
			pthread_create(&philo_tmp->flow_philo, NULL, mode_of_life_philo, (void *)all);
		philo_tmp = philo_tmp->next;
	}
	philo_tmp = philo
	while (philo_tmp)
	{
		if (numer_philo % 2 == 0)
			pthread_create(&philo_tmp->, NULL, mode_of_life_philo, (void *)all);
		philo_tmp = philo_tmp->next;
	}
	philo_tmp = philo;
	while(philo_tmp)
	{
		pthread_join(&philo_tmp->flow_philo, NULL);
		philo_tmp = philo_tmp->next;
	}
	return (0);
}

int live_philo(t_all_progect *all)
{
	birth_philo(all);
	death_philo(all);
	return (0);
}
